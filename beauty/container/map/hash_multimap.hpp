
#ifndef beauty__container__map___hash_multimap_hpp
#define beauty__container__map___hash_multimap_hpp

#include<./beauty/functor/select1st.hpp>
#include<./beauty/functor/identity.hpp>
#include<./beauty/functor/binary_function.hpp>
#include<./beauty/functor/equal_to.hpp>
#include<./beauty/container/pair/pair.hpp>
#include<./beauty/container/pair/make_pair.hpp>
#include<./beauty/container/pair/pair_operator_function.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/container/hashtable/hashtable.hpp>


namespace beauty{namespace container{namespace map{


template<
class Key,
class Value,
class HashFun = beauty::functor::identity<Key>,
class Compare = beauty::functor::equal_to<Key>,
class alloc = beauty::allocator::allocator
>
class hash_multimap{
	public:
	typedef Key                                     key_type;
	typedef Value                                  data_type;
	typedef Compare                              key_compare;
	typedef Compare                               key_equals;

	class value_equals:
		public beauty::functor::binary_function<
			beauty::container::pair::pair<Key,Value>,
			beauty::container::pair::pair<Key,Value>,
			bool>{

		public:
		Compare comp;
		
		value_equals(){}
		
		value_equals(Compare &c):comp(c){}

		public:
		bool operator ()
			(const beauty::container::pair::pair<Key, Value> &x,
				const beauty::container::pair::pair<Key, Value> &y)const{
			return comp(x.first, y.first);
		}
	};

	typedef beauty::container::hashtable::
		hashtable<
		Key,
		beauty::container::pair::pair<Key, Value>,
		beauty::functor::select1st<beauty::container::pair::pair<Key, Value> >,
		Compare,
		HashFun,
		alloc
		>                                               hash_table;


	typedef typename hash_table::iterator                 iterator;
	typedef typename hash_table::const_iterator     const_iterator;
	typedef beauty::container::pair::pair<Key, Value>
												  		value_type;
	typedef typename hash_table::reference               reference;
	typedef typename hash_table::const_reference   const_reference;
	typedef typename hash_table::pointer                   pointer;
	typedef typename hash_table::const_pointer       const_pointer;
	typedef typename hash_table::difference_type   difference_type;
	typedef typename hash_table::size_type               size_type;

	protected:
	typedef hash_multimap<Key, Value, HashFun, Compare, alloc>
											                  self;
	typedef beauty::container::pair::
		pair<iterator, bool>                    pair_iterator_bool;
	typedef beauty::container::pair::
		pair<const_iterator, bool>        pair_const_iterator_bool;
	typedef beauty::container::pair::
		pair<iterator,iterator>             pair_iterator_iterator;
	typedef beauty::container::pair::
		pair<const_iterator,const_iterator>
				                pair_const_iterator_const_iterator;
	hash_table t;

	public:
	hash_multimap(){}

	hash_multimap(size_type n):t(n){}

	hash_multimap(HashFun &hf):t(hf){}
	
	hash_multimap(const Compare&c):t(c){}
	
	hash_multimap(size_type n, HashFun &hf):t(n, hf){}

	hash_multimap(Compare &e_c, HashFun &hf):t(
		beauty::functor::select1st<
		beauty::container::pair::pair<Key, Value> >(),
		e_c, hf){}

	hash_multimap(size_type n, Compare &e_c, HashFun &hf):t(n,
		beauty::functor::select1st<
		beauty::container::pair::pair<Key, Value> >(),
		e_c, hf){}

	hash_multimap(const self &x):t(x.t){}


	void clear(){
		t.clear();
	}
	//
	~hash_multimap(){}



	Compare key_eq()const{
		return t.key_comp();
	}

	value_equals value_eq()const{
		return value_equals();
	}

	iterator begin(){
		return t.begin();
	}

	const_iterator begin()const{
		return t.begin();
	}

	iterator end(){
		return t.end();
	}

	const_iterator end()const{
		return t.end();
	}

	bool is_empty()const{
		return t.empty();
	}

	bool empty()const{
		return t.empty();
	}

	size_type size()const{
		return t.size();
	}

	size_type max_size()const{
		return t.max_size();
	}

	iterator insert(const value_type &v){
		return t.insert_equal(v);
	}

	iterator insert(const key_type &k, const Value &v){
		return t.insert_equal(value_type(k, v));
	}
	
	template<class InputIter>
	void insert(InputIter first, InputIter last){
		t.insert_equal(first, last);
	}

	iterator erase(iterator p){
		t.erase(p++);
		return p;
	}

	void erase(iterator first, iterator last){
		t.erase(first, last);
	}

	size_type erase(const key_type &key){
		return t.erase(key);
	}

	void erase(const key_type *first, const key_type *last){
		t.erase(first, last);
	}

	size_type count(const key_type &key)const{
		return t.count(key);
	}

	iterator lower_bound(const key_type &key){
		return t.lower_bound(key);
	}

	const_iterator lower_bound(const key_type &key)const{
		return t.lower_bound(key);
	}

	iterator upper_bound(const key_type &key){
		return t.upper_bound(key);
	}

	const_iterator upper_bound(const key_type &key)const{
		return t.upper_bound(key);
	}

	pair_iterator_iterator equal_range(const key_type &key){
		return t.equal_range(key);
	}

	pair_const_iterator_const_iterator equal_range(const key_type &key)const{
		return t.equal_range(key);
	}

	iterator find(const key_type &key){
		return t.find(key);
	}

	const_iterator find(const key_type &key)const{
		return t.find(key);
	}

	void swap(self &x){
		t.swap(x.t);
	}

	Value& operator [] (const key_type &k){
		return (*(insert(value_type(k, Value())))).second;
	}

	self& operator = (self &x){
		t = x.t;
		return *this;
	}

};


}
}
}
#endif
