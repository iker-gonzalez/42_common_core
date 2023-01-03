/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:18:34 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/12/03 13:10:22 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

//?https://en.cppreference.com/w/cpp/iterator/reverse_iterator

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft {
		template <class Iter>
		class reverse_iterator {
			
			public:

					//********** ***********//
					//**** MEMBER TYPES ****//
					//********** ***********//

					typedef Iter														iterator_type;
					typedef typename ft::iterator_traits<Iter>::iterator_category		iterator_category;
					typedef typename ft::iterator_traits<Iter>::value_type				value_type;
					typedef typename ft::iterator_traits<Iter>::difference_type			difference_type;
					typedef typename ft::iterator_traits<Iter>::pointer					pointer;
					typedef typename ft::iterator_traits<Iter>::reference				reference;


			protected:

					iterator_type														_it;

			public:

					//********** ***********//
					//**** CONSTRUCTORS ****//
					//********** ***********//

					//?https://cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/

					//default constructor
					reverse_iterator():												_it(0) { };
					//initialization constructor 
					explicit reverse_iterator (iterator_type it): _it(it)					{ };
					//copy constructor	
					reverse_iterator (const reverse_iterator<Iter>& rev_it): _it(rev_it.base())	{ };
					//Base
					iterator_type base() const									{ return (this->_it);};

					~reverse_iterator(void) {}



					//****************** ******************//
					//********* OPERATOR OVERLOADS ********//
					//****************** ******************//

					//?https://en.cppreference.com/w/cpp/iterator/reverse_iterator

					reverse_iterator& operator=( const reverse_iterator<Iter>& other )
					{
						this->_it = other.base();
						return (*this);
					}

					reference operator*() const 
					{
						return (*(--(iterator_type(this->_it))));
					}

					pointer operator->() const
					{
						return (&(*(*this)));
					}

					reference operator[]( difference_type n ) const
					{
						return (this->base()[-n-1]);
					}

					reverse_iterator& operator++()
					{
						--_it;
						return (*this);
					}

					reverse_iterator& operator--()
					{
						++_it;
						return (*this);
					}

					reverse_iterator operator++( int )
					{
						reverse_iterator tmp = *this;
						++_it;
						return (tmp);
					}

					reverse_iterator operator--( int )
					{
						reverse_iterator tmp = *this;
						--_it;
						return (tmp);
					}

					reverse_iterator operator+( difference_type n ) const
					{
						return (reverse_iterator(base() + n));
					}

					reverse_iterator operator-( difference_type n ) const
					{
						return (reverse_iterator(base() - n));
					}

					reverse_iterator& operator+=( difference_type n )
					{
						_it = _it + n;
						return (*this);
					}

					reverse_iterator& operator-=( difference_type n )
					{
						_it = _it - n;
						return (*this);
					}
		};

		//*************** **************//
		//**** NON MEMBER OVERLOADS ****//
		//*************** **************//

		template< class Iterator1, class Iterator2 >
		bool operator==( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs )
		{
			return (lhs.base() == rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator!=( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs )
		{
			return (lhs.base() != rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator<( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs )
		{
			return (lhs.base() < rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator<=( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs )
		{
			return (lhs.base() <= rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator>( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs )
		{
			return (lhs.base() > rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator>=( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs )
		{
			return (lhs.base() >= rhs.base());
		}
}

#endif