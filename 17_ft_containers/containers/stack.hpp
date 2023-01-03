/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:24:27 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/11/24 08:48:13 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "vector.hpp"

namespace ft {
		template <class T, class Container = ft::vector<T> >
		class stack {
		protected:
				//* member object
				Container																			_container;

		public:
				//* member types
				typedef Container																	container_type;
				typedef typename container_type::value_type											value_type;
				typedef typename container_type::size_type											size_type;
	
				//* member functions
				explicit stack (const container_type& ctnr = container_type()):						_container(ctnr) { };
				stack(stack const &other)															{ _container = other._container; };
				~stack()																			{ };
				stack& operator=(const stack &other)												{ if (this == &other) return *this;
																									_container = other._container;
																									return *this; };	
				//* element access
				value_type& top()																	{ return _container.back(); };
				const value_type& top() const														{ return _container.back(); };

				//* capacity
				bool empty() const																	{ return _container.empty(); };
				size_type size() const																{ return _container.size(); };
				
				//* modifiers
				void push (const value_type& val)													{ return _container.push_back(val); };
				void pop()																			{ return _container.pop_back(); };

				//* non-member functions
				friend bool operator==( const stack &lhs, const stack &rhs )						{ return lhs._container == rhs._container; };
				friend bool operator!=( const stack &lhs, const stack &rhs )						{ return lhs._container != rhs._container; };
				friend bool operator<( const stack &lhs, const stack &rhs )							{ return lhs._container < rhs._container; };
				friend bool operator<=( const stack &lhs, const stack &rhs )						{ return lhs._container <= rhs._container; };
				friend bool operator>( const stack &lhs, const stack &rhs )							{ return lhs._container > rhs._container; };
				friend bool operator>=( const stack &lhs, const stack &rhs )						{ return lhs._container >= rhs._container; };
	};
}

#endif
