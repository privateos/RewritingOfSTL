
#ifndef beauty__container__hashtable___hashtable_hpp
#define beauty__container__hashtable___hashtable_hpp

#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/container/hashtable/hashtable_detail/hashtable_prime_list.hpp>
#include<./beauty/container/hashtable/hashtable_detail/hashtable_node.hpp>
#include<./beauty/container/pair/pair.hpp>
#include<./beauty/iterator/iterator_category/forward_iterator_tag.hpp>
#include<./beauty/types.hpp>
#include<./beauty/config.hpp>

namespace beauty{namespace container{namespace hashtable{

template<class Key, class Value, class KeyOfValue,
class EqualCompare, class HashFunction,
 class alloc = beauty::allocator::allocator>
class hashtable{
	protected:
	typedef beauty::container::hashtable::hashtable_detail::
		hashtable_node<Value>				                node;
	typedef node*                                       node_ptr;
	typedef hashtable<Key, Value, KeyOfValue,
			EqualCompare, HashFunction, alloc>              self;
			
	typedef Key                                         key_type;
	
	
	template<class Ref, class Ptr>
	class Iterator{
		public:
		typedef beauty::iterator::iterator_category::
			forward_iterator_tag              iterator_category;
		typedef Value                                value_type;
		typedef Ref                                   reference;
		typedef Ptr                                     pointer;
		typedef beauty::ptrdiff_t               difference_type;
		typedef beauty::size_t                        size_type;
		node *cur;
		self *ht;

		
		Iterator(const Iterator<Ref, Ptr> &x):cur(x.cur), ht(x.ht){}
		
		template<class R, class P>
		Iterator(const Iterator<R, P> &x):cur(x.cur), ht(x.ht){}
		
		Iterator(node *c, self *h):cur(c), ht(h){}
		
		
		reference operator * ()const{
			return cur->value;
		}
		
		pointer operator -> ()const{
			return &(cur->value);
		}
		
		Iterator<Ref, Ptr>& operator ++ (){
			node *p = cur;
			cur = cur->next;
			if(cur == nullptr){
				size_type n = ht->hashvalue(p->value);
				++n;
				while(n < ht->array_size &&
					ht->array[n] == nullptr){
						++n;
				}
				if(n < ht->array_size){
					cur = ht->array[n];
				}
			}
			return *this;
		}
		
		Iterator<Ref, Ptr> operator ++ (int){
			Iterator<Ref, Ptr> tmp(*this);
			++(*this);
			return tmp;
		}
		
		Iterator<Ref, Ptr>& operator = (const Iterator<Ref, Ptr> &x){
			cur = x.cur;
			ht = x.ht;
			return *this;
		}
		
		bool operator == (const Iterator<Ref, Ptr> &x)const{
			return cur == x.cur;
		}
		
		bool operator != (const Iterator<Ref, Ptr> &x)const{
			return cur != x.cur;
		}
	};


	
	public:
	typedef Iterator<Value&, Value*>                    iterator;
	typedef Iterator<const Value&, const Value*>  const_iterator;	
  	typedef Value                                     value_type;
  	typedef Value&                                     reference;
  	typedef const Value&                         const_reference;
  	typedef Value*                                       pointer;
  	typedef const Value*                           const_pointer;
  	typedef beauty::ptrdiff_t                    difference_type;
  	typedef beauty::size_t                             size_type;
  	
	
	//private:
	typedef beauty::allocator::simple_allocator<node*,alloc>
				                                array_allocator;
	typedef beauty::allocator::simple_allocator<node,alloc>
												 data_allocator;
	typedef beauty::container::pair::
		pair<iterator,bool>                  pair_iterator_bool;
	typedef beauty::container::pair::
		pair<const_iterator,bool>      pair_const_iterator_bool;
	typedef beauty::container::pair::
		pair<iterator,iterator>          pair_iterator_iterator;
	typedef beauty::container::pair::
		pair<const_iterator,const_iterator>
		                     pair_const_iterator_const_iterator;

	node_ptr *array;
	size_type array_size;
	size_type num_elements;
	EqualCompare equals;
	HashFunction hash;
	KeyOfValue get_key;
	
	
	node_ptr create_node(const value_type &v){
		node_ptr p = data_allocator::allocate();
		beauty::allocator::function::
			construct(&(p->value), v);
		return p;
	}
	
	void destroy_node(const node_ptr p){
		beauty::allocator::function::
			destroy(&(p->value));
		data_allocator::deallocate(p);
	}
	
	size_type next_size()const{
		return beauty::container::hashtable::
			hashtable_detail::next_prime(array_size);
	}
	
	size_type next_size(size_type n)const{
		return beauty::container::hashtable::
			hashtable_detail::next_prime(n);
	}
	
	void resize(const size_type new_num){
		if(new_num > array_size){
			size_type new_array_size = next_size(new_num);
			if(new_array_size > array_size){
				node_ptr *new_array = 
					array_allocator::allocate(new_array_size);

				size_type n;
				for(n = 0; n < new_array_size; ++n){
					new_array[n] = nullptr;
				}
				
				node_ptr p_node, p_node_next;
				node_ptr *p_array;
				for(p_array = array + array_size - 1;
					p_array >= array; --p_array){
					p_node = *p_array;
					while(p_node != nullptr){
						p_node_next = p_node->next;
						n = hashvalue(p_node->value, new_array_size);
						p_node->next = new_array[n];
						new_array[n] = p_node;
						p_node = p_node_next;
					}
				}
				array_allocator::deallocate(array, array_size);
				
				array = new_array;
				array_size = new_array_size;
			}
		}
	}
	
	size_type hashkey(const key_type &key)const{
		return hash(key)%array_size;
	}
	
	size_type hashkey(const key_type &key, const size_type n)const{
		return hash(key)%n;
	}
	
	size_type hashvalue(const value_type &v)const{
		return hash(get_key(v))%array_size;
	}
	
	size_type hashvalue(const value_type &v, const size_type n)const{
		return hash(get_key(v))%n;
	}
	

	node_ptr lower_bound_help(const Key &key)const{
		size_type n = hashkey(key);
		if(array[n] != nullptr){
			node_ptr p = array[n];
			while(!equals(get_key(p->value), key)){
				p = p->next;
				if(p == nullptr){
					break;
				}
			}
			return p;
		}
		return nullptr;
	}
	
	void erase_range_help(node_ptr first, node_ptr last){

		size_type n = hashvalue(first->value);
		node_ptr p = array[n];
		if(p == first){
			array[n] = last;
		}else{
			while(p->next != first){
				p = p->next;
			}
			p->next = last;
		}

		n = 0;
		while(first != last){
			++n;
			p = first;
			first = first->next;
			destroy(p);
		}

		array_size -= n;
	}
	
	void erase_help(node_ptr p){
		size_type n = hashvalue(p->value);
		if(array[n] == p){
			array[n] = p->next;
		}else{
			node_ptr p0 = array[n];
			while(p0->next != p){
				p0 = p0->next;
			}
			p0->next = p->next;
		}
		destroy_node(p);
		--num_elements;
	}
		
	void initialize(const size_type n){
		array_size = next_size(n);
		array = array_allocator::allocate(array_size);
		size_type i;
		for(i = 0; i < array_size; ++i){
			array[i] = nullptr;
		}
	}
	
	public:
	hashtable():num_elements(0){
		initialize(1);
	}
	
	hashtable(const self &x):num_elements(0){
		initialize(x.num_elements);
		*this = x;
	}
	
	hashtable(HashFunction &hf):hash(hf), num_elements(0){
		initialize(1);
	}
	
	hashtable(size_type n):num_elements(0){
		initialize(n);
	}
	
	hashtable(size_type n, HashFunction &hf):hash(hf), num_elements(0){
		initialize(n);
	}
	
	hashtable(KeyOfValue &k, EqualCompare &e, HashFunction &hf):
		get_key(k), equals(e), hash(hf), num_elements(0){
		initialize(1);
	}
	
	hashtable(size_type n, KeyOfValue &k, EqualCompare &e,
	 HashFunction &hf):
	 	get_key(k), equals(e), hash(hf), num_elements(0){
		initialize(n);
	}
	
	void clear(){
		if(num_elements != 0){
			node_ptr p, p_p;
			size_type n;
			for(n = 0; num_elements != 0; ++n){
				p = array[n];
				while(p != nullptr){
					p_p = p;
					p = p->next;
					destroy_node(p_p);
					-- num_elements;
				}
				array[n] = nullptr;
			}
		}
	}
	
	~hashtable(){
		clear();
		array_allocator::deallocate(array, array_size);
		array = nullptr;
		array_size = 0;
	}
	
	KeyOfValue key_comp()const{
		return equals;
	}
	
	KeyOfValue key_of_value()const{
		return get_key;
	}
	
	bool is_empty()const{
		return num_elements == 0;
	}
	
	bool empty()const{
		return num_elements == 0;
	}

	iterator begin(){
		if(num_elements != 0){
			size_type n;
			for(n = 0; ; ++n){
				if(array[n] != nullptr){
					return iterator(array[n], this);
				}
			}
		}
		return iterator(nullptr, this);
	}
	
	const_iterator begin()const{
		if(num_elements != 0){
			size_type n;
			for(n = 0; ; ++n){
				if(array[n] != nullptr){
					return const_iterator(array[n], const_cast<self*>(this));
				}
			}
		}
		return const_iterator(nullptr, const_cast<self*>(this));
	}
	
	iterator end(){
		return iterator(nullptr, this);
	}
	
	const_iterator end()const{
		return const_iterator(nullptr, const_cast<self*>(this));
	}
	
	size_type size()const{
		return num_elements;
	}
	
	size_type max_size()const{
		return beauty::container::hashtable::
			hashtable_detail::max_bucket_count();
	}
	
	size_type elements_size()const{
		return num_elements;
	}
	
	size_type hashtable_size()const{
		return array_size;
	}
	
	size_type count(const Key &key)const{
		node_ptr p = lower_bound_help(key);
		if(p != nullptr){
			size_type n = 1;
			p = p->next;
			while(p != nullptr &&
				equals(get_key(p->value), key)){
				p = p->next;
				++n;
			}
			return n;
		}
		return 0;
		
	}
	pair_iterator_bool insert_unique(const value_type &v){
		size_type n = hashvalue(v);
		node_ptr p = array[n];
		while(p != nullptr){
			if(equals(get_key(v), get_key(p->value))){
				return pair_iterator_bool(iterator(p, this), false);
			}
			p = p->next;
		}
		resize(num_elements + 1);
		p = create_node(v);
		p->next = array[n];
		array[n] = p;
		++num_elements;
		return pair_iterator_bool(iterator(p, this), true);
	}
	
	pair_const_iterator_bool const_insert_unique(const value_type &v){
		size_type n = hashvalue(v);
		node_ptr p = array[n];
		while(p != nullptr){
			if(equals(get_key(v), get_key(p->value))){
				return pair_const_iterator_bool(const_iterator(p, this), false);
			}
			p = p->next;
		}
		resize(num_elements + 1);
		p = create_node(v);
		p->next = array[n];
		array[n] = p;
		++num_elements;
		return pair_const_iterator_bool(const_iterator(p, this), true);
	}
	
	iterator insert_equal(const value_type &v){
		resize(num_elements + 1);
		node_ptr p = create_node(v);
		size_type n = hashvalue(v);
		p->next = array[n];
		array[n] = p;
		++num_elements;
		return iterator(p, this);
	}
	
	const_iterator const_insert_equal(const value_type &v){
		resize(num_elements + 1);
		node_ptr p = create_node(v);
		size_type n = hashvalue(v);
		p->next = array[n];
		array[n] = p;
		++num_elements;
		return const_iterator(p, this);
	}
	
	template<class InputIter>
	void insert_unique(InputIter first, InputIter last){
		while(first != last){
			insert_unique(*first);
			++first;
		}
	}
	
	template<class InputIter>
	void insert_equal(InputIter first, InputIter last){
		while(first != last){
			insert_equal(*first);
			++first;
		}
	}

	
	void erase(iterator pos){
		if(pos.cur != nullptr && pos.ht == this){
			erase_help(pos.cur);
		}
	}
	

	void erase(iterator first, iterator last){
		if(first.cur == nullptr || first.ht != this){
			return ;
		}
		erase_range_help(first.cur, last.cur);
	}
	
	void erase(const_iterator pos){
		if(pos.cur != nullptr){
			erase_help(pos.cur);
		}
	}
	
	void erase(const_iterator first, const_iterator last){
		if(first.cur == nullptr || first.ht != this){
			return ;
		}
		
		erase_range_help(first.cur, last.cur);
	}

	size_type erase(const Key &key){
		size_type n = hashkey(key);
		if(array[n] != nullptr){
			node_ptr pd = array[n];
			node_ptr pd_p = nullptr, pd_n;
			while(!equals(get_key(pd->value), key)){
				pd_p = pd;
				if(pd->next == nullptr){
					return 0;
				}
				pd = pd->next;
			}
			pd_n = pd->next;
			if(pd_n != nullptr){
				while(equals(get_key(pd_n->value), key)){
					pd_n = pd_n->next;
					if(pd_n == nullptr){
						break;
					}
					
				}
			}
			
			if(pd_p == nullptr){
				array[n] = pd_n;
			}else{
				pd_p->next = pd_n;
			}
			
			n = 0;
			while(pd != pd_n){
				++n;
				pd_p = pd;
				pd = pd->next;
				destroy_node(pd_p);
			}
			num_elements -= n;
			return n;
		}
		return 0;
	}

	void erase(const Key *first, const Key *last){
		while(first != last){
			erase(*first);
			++first;
		}
	}

	
	iterator lower_bound(const Key &key){
		return iterator(lower_bound_help(key), this);
	}
	
	const_iterator lower_bound(const Key &key)const{
		return const_iterator(lower_bound_hlep(key), this);
	}
	
	iterator upper_bound(const Key &key){
		node_ptr p = lower_bound_hlep(key);
		if(p != nullptr){
			while(equals(get_key(p->value), key)){
				p = p->next;
				if(p == nullptr){
					break;
				}
			}
			return iterator(p, this);
		}
		return iterator(p, this);
	}
	
	const_iterator uppper_bound(const Key &key)const{
		node_ptr p = lower_bound_hlep(key);
		if(p != nullptr){
			while(equals(get_key(p->value), key)){
				p = p->next;
				if(p == nullptr){
					break;
				}
			}
			return iterator(p, this);
		}
		return iterator(p, this);
	}
	
	pair_iterator_iterator equal_range(const Key &key){
		node_ptr p = lower_bound_help(key);
		if(p != nullptr){
			node_ptr pn = p->next;
			while(pn != nullptr &&
				equals(get_key(pn->value), key)){
				pn = pn->next;
			}
			return pair_iterator_iterator(
			iterator(p, this), iterator(pn, this));
		}
		return pair_iterator_iterator(
		iterator(p, this), iterator(p, this));
	}
	
	pair_const_iterator_const_iterator
		const_equal_range(const Key &key)const{
		node_ptr p = lower_bound_help(key);
		if(p != nullptr){
			node_ptr pn = p->next;
			while(pn != nullptr &&
				equals(get_key(pn->value), key)){
				pn = pn->next;
			}
			return pair_const_iterator_const_iterator(
				const_iterator(p, this),
				const_iterator(pn, this));
		}
		return pair_const_iterator_const_iterator(
			const_iterator(p, this),
			const_iterator(p, this));
	}
	
	node_ptr find_help(const Key &key)const{
		size_type n = hashkey(key);
		if(array[n] != nullptr){
			node_ptr p = array[n];
			while(!equals(key, get_key(p->value))){
				if(p->next == nullptr){
					return nullptr;
				}
				p = p->next;
			}
			return p;
		}
		return nullptr;
	}
	iterator find(const Key &key){
		return iterator(find_help(key), this);
	}
	
	const_iterator find(const Key &key)const{
		return const_iterator(find_help(key), const_cast<self*>(this));
	}
	
	void swap(self &x){
		if(this != &x){
			node_ptr p = array;
			array = x.array;
			x.array = p;
			
			size_type a_s = array_size;
			array_size = x.array_size;
			x.array_size = a_s;
			
			a_s = num_elements;
			num_elements = x.num_elements;
			x.num_elements = a_s;
			
			KeyOfValue tk = get_key;
			get_key = x.get_key;
			x.get_key = tk;
			
			EqualCompare te = equals;
			equals = x.equals;
			x.equals = te;
			
			HashFunction thf = hash;
			hash = x.hash;
			x.hash = thf;
		}
	}
	
	self& operator = (const self &x){
		if(this != &x){
			clear();

			size_type n = x.array_size;
			
			if(array_size < n){
				array_allocator::deallocate(array, array_size);
				array_size = n;
				array = array_allocator::allocate(array_size);
				for(n = 0; n < array_size; ++n){
					array[n] = nullptr;
				}
			}
			
			node_ptr p;
			node_ptr *p_a;
			n = x.num_elements;
			for(p_a = x.array; n != 0; ++p_a){
				p = *p_a;
				while(p != nullptr){
					--n;
					insert_equal(p->value);
					p = p->next;
				}
			}
			
		}
		
		return *this;
	}
	
	
	
	
};


}
}
}
#endif
