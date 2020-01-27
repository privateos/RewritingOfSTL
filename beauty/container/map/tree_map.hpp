
#ifndef beauty__container__map___tree_map_hpp
#define beauty__container__map___tree_map_hpp

#include<./beauty/functor/select1st.hpp>
#include<./beauty/functor/binary_function.hpp>
#include<./beauty/functor/less.hpp>
#include<./beauty/container/pair/pair.hpp>
#include<./beauty/container/pair/make_pair.hpp>
#include<./beauty/container/pair/pair_operator_function.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/container/tree/rb_tree.hpp>


namespace beauty{namespace container{namespace map{
	
	
template<
class Key,
class Value,
class Compare = beauty::functor::less<Key>,
class alloc = beauty::allocator::allocator,

class Tree = beauty::container::tree::
  rb_tree<Key,
beauty::container::pair::pair<Key, Value>,
  beauty::functor::select1st<beauty::container::pair::pair<Key, Value> >,
  Compare,
  alloc>  
  
>
class tree_map{
	public:
	typedef Key                                     key_type;
	typedef Value                                  data_type;
	typedef Compare                              key_compare;
	
	class value_compare:
		public beauty::functor::binary_function<
			beauty::container::pair::pair<Key,Value>,
			beauty::container::pair::pair<Key,Value>, 
			bool>{
		
		protected:
		Compare comp;
		value_compare(Compare &c):comp(c){}
		
		public:
		bool operator () 
			(const beauty::container::pair::pair<Key, Value> &x, 
				const beauty::container::pair::pair<Key, Value> &y)const{
			return comp(x.first, y.first);
		}
	};
	
	
	
	typedef typename Tree::iterator                 iterator;
	typedef typename Tree::const_iterator     const_iterator;
	typedef beauty::container::pair::pair<Key, Value>
												  value_type;
	typedef typename Tree::reference               reference;
	typedef typename Tree::const_reference   const_reference;
	typedef typename Tree::pointer                   pointer;
	typedef typename Tree::const_pointer       const_pointer;
	typedef typename Tree::difference_type   difference_type;
	typedef typename Tree::size_type               size_type;
	
	protected:	
	typedef tree_map<Key, Value, Compare, alloc, Tree>
											            self;
	typedef beauty::container::pair::
		pair<iterator, bool>              pair_iterator_bool;
	typedef beauty::container::pair::
		pair<const_iterator, bool>  pair_const_iterator_bool;
	typedef beauty::container::pair::
		pair<iterator,iterator>       pair_iterator_iterator;
	typedef beauty::container::pair::
		pair<const_iterator,const_iterator>       
				         pair_const_iterator_const_iterator;
	Tree t;
	
	public:
	tree_map(){}
	
	tree_map(const Compare&c):t(c){}
	
	tree_map(const self &x):t(x.t){}
	
	
	void clear(){
		t.clear();
	}	
	//
	~tree_map(){}
	

	
	Compare key_comp()const{
		return t.key_comp();
	}
	
	Compare value_comp()const{
		return value_compare();
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
	
	pair_iterator_bool insert(const value_type &v){
		return t.insert_unique(v);
	}
	
	pair_iterator_bool insert(const key_type &k, const Value &v){
		return t.insert_unique(value_type(k, v));
	}
	
	template<class InputIter>
	void insert(InputIter first, InputIter last){
		t.insert_unique(first, last);
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
		return (*((insert(value_type(k, Value()))).first)).second;
	}
	
	self& operator = (self &x){
		t = x.t;
		return *this;
	}
	
	bool operator == (const self &x)const{
		return t == x.t;
	}
	
	bool operator != (const self &x)const{
		return t != x.t;
	}
	
	bool operator < (const self &x)const{
		return t < x.t;
	}
	
	bool operator >= (const self &x)const{
		return t >= x.t;
	}
	
	bool operator > (const self &x)const{
		return t > x.t;
	}
	
	bool operator <= (const self &x)const{
		return t <= x.t;
	}
	
	
};


}
}
}
#endif
