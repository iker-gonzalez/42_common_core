/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:45:52 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/12/05 14:17:45 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

namespace ft {

	//****************** ******************//
	//************* IS_INTEGRAL ***********//
	//****************** ******************//

	template <class T>
	struct is_integral: public std::integral_constant <bool, false> {};
	template < >
	struct is_integral<char> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<char16_t> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<char32_t> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<wchar_t> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<signed char> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<short int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<long int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<long long int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned char> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned short int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned long int> : public std::integral_constant <bool, true> {};
	template < >
	struct is_integral<unsigned long long int> : public std::integral_constant <bool, true> {};
	
	//****************** ******************//
	//************** ENABLE_IF ************//
	//****************** ******************//

	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct  enable_if <true, T> { typedef T type; };

	//****************** ******************//
	//***** LEXICOGRAPHICAL COMPARE *******//
	//****************** ******************//

	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
	{
		while (first1 != last1 && first2 != last2)
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
			++first1;
			++first2;
		}
		return (false);
	}
	
	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp )
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
 		return (false);
	}

	//****************** ******************//
	//************** EQUAL ****************//
	//****************** ******************//

	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
	{
		for (; first1 != last1; ++first1, ++first2) 
		{
			if (!(*first1 == *first2))
				return false;
		}
		return true;
	}

	template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p )
	{
		for (; first1 != last1; ++first1, ++first2) 
		{
			if (!p(*first1, *first2))
				return false;
		}
		return true;
	}

	//****************** ******************//
	//************** PAIR *****************//
	//****************** ******************//

	template <class T1, class T2> 
	struct pair {

		// member types
		typedef T1 first_type;
		typedef T2 second_type;
		
		// member objects
		first_type first;
		second_type second;

		// member functions
		pair(): first(), second() {};
		pair( const first_type& x, const second_type& y ): first(x), second(y) {};
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ): first(p.first), second(p.second) {};
		~pair(void) {};
		pair& operator=( const pair& other )
		{
			first = other.first;
			second = other.second;
			return (*this);
		}
	};

	//****************** ******************//
	//***** PAIR NON MEMBER FUNCTIONS *****//
	//****************** ******************//

	template< class T1, class T2 >
	pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return (pair<T1, T2>(t, u));
	}

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first != rhs.first && lhs.second != rhs.second);
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second));
	}

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first <= rhs.first || (!(lhs.first <= rhs.first) && lhs.second <= rhs.second));
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first > rhs.first || (!(lhs.first > rhs.first) && lhs.second > rhs.second));
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first >= rhs.first || (!(lhs.first >= rhs.first) && lhs.second >= rhs.second));
	}
}

#endif