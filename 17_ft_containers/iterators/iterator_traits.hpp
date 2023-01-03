/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:50:24 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/28 09:04:17 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

# include <iostream>
# include <memory>
#include <iterator>

//?https://en.cppreference.com/w/cpp/iterator/iterator_traits

/*
	std::iterator_traits is the type trait class that provides uniform
	interface to the properties of LegacyIterator types. This makes it
	possible to implement algorithms only in terms of iterators.
	
	The template can be specialized for user-defined iterators so that
	the information about the iterator can be retrieved even if the type
	does not provide the usual typedefs.
*/

//?https://cplusplus.com/reference/iterator/iterator_traits/

/*
	Traits class defining properties of iterators.

	Standard algorithms determine certain properties of the iterators passed
	to them and the range they represent by using the members of the
	corresponding iterator_traits instantiation.

	For every iterator type, a corresponding specialization of iterator_traits
	class template shall be defined, with at least the following member types defined:
*/

	//********************************************************* *********************************************************//
	//************* MEMBER ************  ***************************** DESCRIPTION **************************************//
	//********************************************************* *********************************************************//
	//          difference_type        //      Type to express the result of subtracting one iterator from another       //
	//          value_type             //      The type of the element the iterator can point to                         //
	//          pointer                //      The type of a pointer to an element the iterator can point to             //
	//          reference              //      The type of a reference to an element the iterator can point to           //
	//          iterator_category      //      The iterator category. It can be one of these:                            //
	//                .                //      1. input_iterator_tag                                                     //
	//                .                //      2. output_iterator_tag                                                    //
	//                .                //      3. forward_iterator_tag                                                   //
	//                .                //      4. bidirectional_iterator_tag                                             //
	//                .                //      5. random_access_iterator_tag                                             //
	//********************************************************* *********************************************************//

namespace ft {

	template<typename Iter>
	struct iterator_traits {
			public:
				typedef typename Iter::iterator_category	iterator_category;
				typedef typename Iter::value_type			value_type;
				typedef typename Iter::pointer				pointer;
				typedef typename Iter::reference			reference;
				typedef typename Iter::difference_type		difference_type;
	};

	//*************** ***************//
	//******* SPECIALIZATIONS *******//
	//*************** ***************//

	//T* specialization member types
	template <class T>
	struct iterator_traits<T*> {
			public:
				typedef	std::ptrdiff_t						difference_type;
				typedef	T									value_type;
				typedef T*									pointer;
				typedef T&									reference;
				typedef	std::random_access_iterator_tag		iterator_category;
	};

	//const T* specialization member types
	template <class T>
	struct iterator_traits<const T*> {
			public:
				typedef	std::ptrdiff_t						difference_type;
				typedef	T									value_type;
				typedef T*									pointer;
				typedef T&									reference;
				typedef	std::random_access_iterator_tag		iterator_category;
	};

}

#endif