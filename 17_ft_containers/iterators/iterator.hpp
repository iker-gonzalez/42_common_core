/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:00:25 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/10/18 08:39:30 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"

//?https://cplusplus.com/reference/iterator/iterator/

/* This is a base class template that can be used to derive
iterator classes from it. It is not an iterator class and
does not provide any of the functionality an iterator is
expected to have. */

	//*************** ***************//
	//***** ITERATORS HIERARCHY *****//
	//*************** ***************//
/*

	Input <-- Forward <-- Bidirectional <-- Random Access
	Output
	
*/

namespace ft {

	class input_iterator_tag {};
	class output_iterator_tag {};
	class forward_iterator_tag: public input_iterator_tag {};
	class bidirectional_iterator_tag: public forward_iterator_tag {};
	class random_access_iterator_tag: public bidirectional_iterator_tag {};
}

#endif