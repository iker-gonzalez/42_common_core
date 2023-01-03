/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:43:53 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/28 09:04:12 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../utils/utility.hpp"

//?https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
//?https://cplusplus.com/reference/iterator/RandomAccessIterator/

/* 
	Random-access iterators are iterators that can be used to access elements
	at an arbitrary offset position relative to the element they point to, offering
	the same functionality as pointers.

	Random-access iterators are the most complete iterators in terms of functionality.
	All pointer types are also valid random-access iterators.

	There is not a single type of random-access iterator: Each container may define its
	own specific iterator type able to iterate through it and access its elements. But all
	random access iterators support -at least- the following operations specified on this library.
*/

namespace ft {
	
		template<typename T>
		class random_access_iterator {
				public:
						typedef ft::random_access_iterator_tag				iterator_category;
						typedef T											value_type;
						typedef T*											pointer;
						typedef T&											reference;
						typedef	std::ptrdiff_t								difference_type;
						typedef random_access_iterator<T>					iterator;

				protected:
						pointer												_ptr;
			
				//*************** ***************//
				//******* CANONICAL FORM ********//
				//*************** ***************//
				
				public:
						random_access_iterator(void): _ptr(NULL) { };
						random_access_iterator(pointer _ptr): _ptr(_ptr) { };
						random_access_iterator(random_access_iterator const& src) { *this = src; };
						random_access_iterator& operator= (const random_access_iterator& cp) 
						{ if (this != &cp) _ptr = cp._ptr; return *this; };
						~random_access_iterator(void) { };

				//*************** ***************//
				//****** OPERATOR OVERLOAD ******//
				//*************** ***************//

				bool operator==(const iterator& b) { return this->_ptr == b._ptr; };
				bool operator!=(const iterator& b) { return this->_ptr != b._ptr; };
				//dereferenced as an rvalue
				reference operator* () { return *_ptr; };
				reference operator* () const { return *_ptr; };
				pointer operator-> () const { return _ptr; }; ;
				iterator& operator++ (void) { (this->_ptr)++; return *this; };
				iterator operator++ (int) { iterator it = *this; (this->_ptr)++; return it; };
				iterator& operator-- (void) { (this->_ptr)--; return *this; };
				iterator operator-- (int) { iterator it = *this; (this->_ptr)--; return it; };
				//Arithmetic operators + and - between an iterator and an integer value.
				iterator operator+ (int nb) { return iterator(this->_ptr + nb); };
				iterator operator- (int nb) { return iterator(this->_ptr - nb); };
				//Substracting an iterator from another
				difference_type operator- (const iterator b) { return this->_ptr - b._ptr; };
				//compound assignment operations += and -=
				iterator& operator+= (difference_type n) { this->_ptr += n; return *this; };
				iterator& operator-= (difference_type n) { this->_ptr -= n; return *this; };
				//comparation between two iterators
				bool operator> (const iterator b) { return this->_ptr > b._ptr; };
				bool operator>= (const iterator b) { return this->_ptr >= b._ptr; };
				bool operator< (const iterator b) { return this->_ptr < b._ptr; };
				bool operator<= (const iterator b) { return this->_ptr <= b._ptr; };
				//offset dereference operator ([])
				reference operator[] (difference_type n) { return (*(this->_ptr + n)); };
	};
}

#endif