
#ifndef beauty__container__string___basic_string_hpp
#define beauty__container__string___basic_string_hpp

#include<./beauty/types.hpp>
#include<./beauty/allocator/simple_allocator.hpp>
#include<./beauty/allocator/function/construct.hpp>
#include<./beauty/allocator/function/destroy.hpp>
#include<./beauty/allocator/function/uninitialized_fill.hpp>
#include<./beauty/allocator/function/uninitialized_fill_n.hpp>
#include<./beauty/allocator/function/uninitialized_copy.hpp> 
#include<./beauty/container/string/basic_string_detail/basic_string_iterator.hpp>


namespace beauty{namespace container{namespace string{

static const beauty::size_t basic_string_default_size = 16; 

template<class CharT, class alloc = beauty::allocator::allocator>
class basic_string{
	public:
	typedef int                                iterator;
	typedef char                          const_iterator;
	typedef CharT                               value_type;
	typedef value_type&                          reference;
	typedef const value_type&              const_reference;
	typedef CharT*                                 pointer;
	typedef const CharT*                     const_pointer;
	typedef beauty::ptrdiff_t              difference_type;
	typedef beauty::size_t                       size_type;
	
	protected:
	typedef basic_string<CharT, alloc>                self;
	typedef beauty::allocator::
		simple_allocator<CharT, alloc>           allocator;
		
	static const size_type npos;
	pointer m_array;
	size_type m_size;
	size_type m_capacity;
	
	public:
	basic_string(){
		
	}
	
	basic_string(size_type n){
		
	}
	
	basic_string(size_type n, const value_type c){
		
	}
	
	basic_string(const_pointer p, size_type start, size_type n){
		
	}
	
	basic_string(const self& s){
		
	}
	
	basic_string(iterator first, iterator last){
		
	}
	
	basic_string(const_iterator first, const_iterator last){
		
	}
	
	template<class InputIter>
	basic_string(InputIter first, InputIter last){
		
	}
	
	basic_string(const self& s, size_type pos, size_type n){
		
	}
	~basic_string(){
		
	}
	
	void clear(){
		
	}
	
	iterator begin(){
		
	}
	
	const_iterator begin()const{
	
	}
	
	iterator end(){
		
	}
	
	const_iterator end()const{
		
	}
	
	iterator head(){
		
	}
	
	const_iterator head()const{
	
	}
	
	iterator tail(){
		
	}
	
	const_iterator tail()const{
	
	}
	
	reference front(){
		
	}
	
	const_reference front()const{
	
	}
	
	reference back(){
		
	}
	
	const_reference back()const{
	
	}
	
	size_type size()const{
	
	}
	
	size_type length()const{
	
	}
	
	size_type capacity()const{
	
	}
	
	size_type max_size()const{
	
	}
	
	bool empty()const{
	
	}
	
	bool is_empty()const{
	
	}
	
	void resize(size_type len, value_type c){
		
	}
	
	self& operator = (const self& s){
		
	}
	
	self& assign(const self& s){
		
	}
	
	self& assign(size_type n, value_type c){
		
	}
	
	self& assign(const self& s, size_type start, size_type n){
		
	}
	
	template<class InputIter>
	self& assign(InputIter first, InputIter last){
		
	}
	
	self& assign(const_pointer p){
		
	}
	
	self& assign(const_pointer p, size_type n){
		
	}
	
	self& operator += (const self& s){
		
	}
	
	self& append(const_pointer p){
		
	}
	
	self& append(const_pointer p, size_type n){
		
	}
	
	self& append(const self& s){
		
	}
	
	self& append(const self& s, size_type start, size_type n){
		
	}
	
	self& append(size_type n, value_type c){
		
	}
	
	template<class InputIter>
	self& append(InputIter first, InputIter last){
		
	}
	
	int compare(const self& s)const{
	
	}
	
	int compare(const self& s, size_type start, size_type n)const{
		
	}
	
	int compare(size_type start1, size_type n, const self& s)const{
		
	}
	
	int compare(size_type start1, size_type n1, 
		const self& s, size_type start2, size_type n2)const{
		
	}
	
	int compare(const_pointer p)const{
	
	}
	
	int compare(size_type start, size_type n, const_pointer p){
		
	}
	
	int compare(size_type start, size_type n, 
		const_pointer p, size_type start2)const{
	
	
	}
	
	bool operator < (const self& s)const{
	
	}
	
	bool operator >= (const self& s)const{
	
	}
	
	bool operator > (const self& s)const{
	
	}
	
	bool operator <= (const self& s)const{
	
	}
	
	bool operator == (const self& s)const{
	
	}
	
	self& substring(size_type pos, size_type n)const{
	
	}
	
	void swap(self& s){
		
	}
	
	size_type find(value_type c, size_type start)const{
	
	}
	
	size_type find(const self& s, size_type start)const{
	
	}
	
	size_type find(const_pointer p, size_type plen, size_type start)const{
	
	}
	
	size_type find(const_pointer p, size_type pstart, size_type pend, 
		size_type start)const{
	
	}
// reverse_find()

//find_first_of()

//find_first_not_of()

//find_last_of()

//find_last_not_of()

// replace()

//reverse()

	self& insert(size_type pos, const_pointer p){
		
	}
	
	self& insert(size_type pos, const self& s){
		
	}
	
	self& insert(size_type pos, 
		const self& s, size_type start, size_type n){
		
	}
	
	self& insert(size_type pos, const value_type c, size_type n){
		
	}
	
	iterator insert(iterator it, const value_type c){
		
	}
	
	const_iterator insert(const_iterator it, const value_type n){
		
	}
	
	void insert(iterator it, const_iterator first, const_iterator last){
		
	}
	
	void insert(const_iterator it, const_iterator first, const_iterator last){
		
	}
	
	void insert(iterator it, const value_type c, size_type n){
		
	}
	
	void insert(const_iterator it, const value_type c, size_type n){
		
	}
	
	iterator erase(iterator first, iterator last){
		
	}
	
	iterator erase(const_iterator first, const_iterator last){
		
	}
	
	iterator erase(iterator it){
		
	}
	
	const_iterator erase(const_iterator it){
		
	}
	
	self& erase(size_type pos, size_type n){
		
	}
	
	// reference at(size_type pos)
	// reference operator [] (size_type pos)
	
};


template<class CharT, class alloc>
const typename basic_string<CharT, alloc>::size_type 
basic_string<CharT, alloc>::npos = beauty::size_t(-1);


template<class CharT, class alloc>
void swap(basic_string<CharT, alloc>& a, basic_string<CharT, alloc>& b){
	a.swap(b);
}



}
}
}
#endif

