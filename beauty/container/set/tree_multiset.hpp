
#ifndef beauty__container__set___tree_multiset_hpp
#define beauty__container__set___tree_multiset_hpp

#include<./beauty/functor/identity.hpp>
#include<./beauty/functor/less.hpp>
#include<./beauty/container/pair/pair.hpp>
#include<./beauty/container/pair/make_pair.hpp>
#include<./beauty/container/pair/pair_operator_function.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/container/tree/rb_tree.hpp>


namespace beauty{namespace container{namespace set{


template<
class Key,
class Compare = beauty::functor::less<Key>,
class alloc = beauty::allocator::allocator,
class Tree = beauty::container::tree::
  rb_tree<Key,Key,beauty::functor::identity<Key>, Compare,alloc>
>
class tree_multiset{
	public:
	typedef Key                                     key_type;
	//typedef Key                                   value_type;
	typedef Compare                              key_compare;
	typedef Compare                            value_compare;

	typedef typename Tree::const_iterator           iterator;
	typedef iterator                          const_iterator;
	typedef Key                                   value_type;
	typedef typename Tree::const_reference         reference;
	typedef reference                        const_reference;
	typedef typename Tree::const_pointer             pointer;
	typedef pointer                            const_pointer;
	typedef typename Tree::difference_type   difference_type;
	typedef typename Tree::size_type               size_type;

	protected:
	typedef tree_multiset<Key,Compare,alloc,Tree>       self;
	typedef beauty::container::pair::
		pair<iterator,iterator>       pair_iterator_iterator;
	typedef typename Tree::iterator            Tree_iterator;
	Tree t;

	public:
	tree_multiset(){}

	tree_multiset(const Compare&c):t(c){}

	tree_multiset(const self &x):t(x.t){}


	void clear(){
		t.clear();
	}
	//
	~tree_multiset(){}



	Compare key_comp()const{
		return t.key_comp();
	}

	Compare value_comp()const{
		return t.key_comp();
	}

	iterator begin()const{
		return t.begin();
	}

	iterator end()const{
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
		return t.const_insert_equal(v);
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

	iterator lower_bound(const key_type &key)const{
		return t.const_lower_bound(key);
	}

	iterator upper_bound(const key_type &key)const{
		return t.const_upper_bound(key);
	}

	pair_iterator_iterator equal_range(const key_type &key)const{
		return t.const_equal_range(key);
	}

	iterator find(const key_type &key)const{
		return t.find(key);
	}

	void swap(self &x){
		t.swap(x.t);
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
