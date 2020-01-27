
#ifndef beauty___exception_hpp
#define beauty___exception_hpp

#include<./beauty/header.hpp>

namespace beauty{

class exception{
	public:
	const char *throw_path;
	const char *throw_file;
	const char *throw_namespace;
	const char *throw_class;
	const char *throw_function;
	const char *throw_what;
	
	const char *catch_path;
	const char *catch_file;
	const char *catch_namespace;
	const char *catch_class;
	const char *catch_function;
	const char *catch_what;

	exception():throw_path("null"), throw_file("null"),
			throw_namespace("null"), throw_class("null"),
			throw_function("null"), throw_what("null"),
			catch_path("null"), catch_file("null"),
			catch_namespace("null"), catch_class("null"),
			catch_function("null"), catch_what("null"){}
			
	
	exception(const char *t_path, const char *t_file, const char *t_namespace,
		const char *t_class, const char *t_function, const char *t_what):
			throw_path(t_path), throw_file(t_file),
			throw_namespace(t_namespace), throw_class(t_class),
			throw_function(t_function), throw_what(t_what),
			catch_path("null"), catch_file("null"),
			catch_namespace("null"), catch_class("null"),
			catch_function("null"), catch_what("null"){}
			
			
	
	void set_throw_path(const char *p){
		throw_path = p;
	}
	void set_throw_file(const char *p){
		throw_file = p;	
	}
	void set_throw_namespace(const char *p){
		throw_namespace = p;
	}
	void set_throw_class(const char *p){
		throw_class = p;
	}
	void set_throw_function(const char *p){
		throw_function = p;	
	}
	void set_throw_what(const char *p){
		throw_what = p;	
	}
	void set_catch_path(const char *p){
		catch_path = p;	
	}
	void set_catch_file(const char *p){
		catch_file = p;	
	}
	void set_catch_namespace(const char *p){
		catch_namespace = p;	
	}
	void set_catch_class(const char *p){
		catch_class = p;	
	}
	void set_catch_function(const char *p){
		catch_function = p;	
	}
	void set_catch_what(const char *p){
		catch_what = p;	
	}
	
	void set_throw(const char *path, const char *file, const char *_namespace,
					const char *_class, const char *function, const char *what){
		throw_path = path;
		throw_file = file;
		throw_namespace = _namespace;
		throw_class = _class;
		throw_function = function;
		throw_what = what;			
	}
	void set_catch(const char *path, const char *file, const char *_namespace,
					const char *_class, const char *function, const char *what){
	
		catch_path = path;
		catch_file = file;
		catch_namespace = _namespace;
		catch_class = _class;
		catch_function = function;
		catch_what = what;			
	}
	
	
	const char* get_throw_path()const{
		return throw_path;
	}
	const char* get_throw_file()const{
		return throw_file;	
	}
	const char* get_throw_namespace()const{
		return throw_namespace;	
	}
	const char* get_throw_class()const{
		return throw_class;	
	}	
	const char* get_throw_function()const{
		return throw_function;
	}
	const char* get_throw_what()const{
		return throw_what;	
	}
	const char* get_catch_path()const{
		return catch_path;	
	}
	const char* get_catch_file()const{
		return catch_file;	
	}
	const char* get_catch_namespace()const{
		return catch_namespace;	
	}
	const char* get_catch_class()const{
		return catch_class;	
	}
	const char* get_catch_function()const{
		return catch_function;	
	}
	const char* get_catch_what()const{
		return catch_what;	
	}
	
	
	
	void print_throw_path()const{
		std::cerr<<"throw_path: "<<throw_path<<std::endl;
	}
	void print_throw_file()const{
		std::cerr<<"throw_file: "<<throw_file<<std::endl;
	}
	void print_throw_namespace()const{
		std::cerr<<"throw_namespace: "<<throw_namespace<<std::endl;	
	}
	void print_throw_class()const{
		std::cerr<<"throw_class: "<<throw_class<<std::endl;	
	}
	void print_throw_function()const{
		std::cerr<<"throw_function: "<<throw_function<<std::endl;	
	}
	void print_throw_what()const{
		std::cerr<<"throw_what: "<<throw_what<<std::endl;	
	}
	
	void print_catch_path()const{
		std::cerr<<"catch_path: "<<catch_path<<std::endl;
	}
	void print_catch_file()const{
		std::cerr<<"catch_file: "<<catch_file<<std::endl;	
	}
	void print_catch_namespace()const{
		std::cerr<<"catch_namespace: "<<catch_namespace<<std::endl;	
	}
	void print_catch_class()const{
		std::cerr<<"catch_class: "<<catch_class<<std::endl;	
	}
	void print_catch_function()const{
		std::cerr<<"catch_function: "<<catch_function<<std::endl;	
	}
	void print_catch_what()const{
		std::cerr<<"catch_function: "<<catch_what<<std::endl;	
	}
	void print_throw()const{
		print_throw_path();
		print_throw_file();
		print_throw_namespace();
		print_throw_class();
		print_throw_function();
		print_throw_what();	
	}
	void print_catch()const{
		print_catch_path();
		print_catch_file();
		print_catch_namespace();
		print_catch_class();
		print_catch_function();
		print_catch_what();	
	}
	
	void print(){
		print_throw();
		std::cerr<<std::endl;
		print_catch();
		std::cerr<<std::endl<<std::endl<<std::endl;
	}
};



}
#endif
