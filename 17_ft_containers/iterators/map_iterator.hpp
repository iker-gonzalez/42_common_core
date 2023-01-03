/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:24:27 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/12/05 11:42:15 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR
#define MAP_ITERATOR

#include "iterator.hpp"
#include "../containers/BST.hpp"
#include "../containers/map.hpp"
#include "../utils/utility.hpp"

namespace ft {
	/*
	*   @param Node                 A pointer to a node in the BST.
	*   @param key_value_pair       
	*/

	template <typename Node, typename key_value_pair>
	class map_iterator
	{
		public:

				typedef typename ft::bidirectional_iterator_tag						iterator_category;
				typedef typename ft::iterator_traits<Node>::value_type				node;
				typedef typename ft::iterator_traits<Node>::difference_type			difference_type;
				typedef typename ft::iterator_traits<Node>::pointer					node_ptr;
				typedef typename ft::iterator_traits<Node>::reference				node_ref;
				typedef key_value_pair												value_type;
				typedef key_value_pair*												pointer;
				typedef key_value_pair&												reference;

		private:

				node_ptr															_node;
				node_ptr															_begin;
				node_ptr															_end;

		public:
		
				//********************** **********************//
				//*** CONSTRUCTORS - DESTRUCTOR - OPERATOR= ***//
				//********************** **********************//

		/** Constructors **/
		map_iterator(node_ptr node = 0) : _node(node)
		{
			node_ptr	tmp(node);

			if (node && (tmp || tmp == this->_end))
			{
				while (tmp->parent && tmp->parent->parent)
					tmp = tmp->parent;
				while (tmp->left)
					tmp = tmp->left;
				this->_begin = tmp;
				tmp = node;
				while (tmp->parent)
					tmp = tmp->parent;
				this->_end = tmp;
			}
			else
			{
				this->_begin = 0;
				this->_end = 0;
			}
			return ;
		}

		template < typename UNode, typename U >
		map_iterator(const map_iterator<UNode, U>& other)
			: _node(other.root()), _begin(other.begin()), _end(other.end())
		{
			return ;
		}

				/** Destructor **/
				~map_iterator(void) {}

				/** Assignation Operator **/
				map_iterator&	operator=(const map_iterator& other)
				{
					this->_node = other.root();
					this->_begin = other.begin();
					this->_end = other.end();
					return (*this);
				}

				//****************** ******************//
				//*************** GETTERS *************//
				//****************** ******************//

				node_ptr root(void) const
				{
					return (this->_node);
				}

				node_ptr begin(void) const
				{
					return (this->_begin);
				}

				node_ptr end(void) const
				{
					return (this->_end);
				}

				//****************** ******************//
				//******** OPERATOR OVERLOADS *********//
				//****************** ******************//

				reference operator*(void) const
				{
					return (this->_node->data);
				}

				pointer operator->(void) const
				{
					return (&(this->_node->data));
				}

				map_iterator& operator++(void)
				{
					node_ptr	output;

					output = this->_node;
					if (output && output->right)
					{
						output = output->right;
						while (output->left)
							output = output->left;
					}
					else if (output != this->_end)
					{
						while (output->parent && output != output->parent->left)
							output = output->parent;
						output = output->parent;
					}
					this->_node = output;
					return (*this);
				}

				map_iterator operator++(int)
				{
					map_iterator output(*this);

					++(*this);
					return (output);
				}

				map_iterator& operator--(void)
				{
					node_ptr	output;

					output = this->_node;
					if (output && output->left)
					{
						output = output->left;
						while (output->right)
							output = output->right;
					}
					else if (output != this->_begin)
					{
						while (output->parent && output != output->parent->right)
							output = output->parent;
						output = output->parent;
					}
					this->_node = output;
					return (*this);
				}

				map_iterator operator--(int)
				{
					map_iterator output(*this);

					--(*this);
					return (output);
				}
	};

	//****************** ******************//
	//******** RELATIONAL OPERATORS *******//
	//****************** ******************//

	/** Relational Operators **/
	template < typename Node, typename key_value_pair >
	bool	operator==(const map_iterator<Node, key_value_pair>& lhs, const map_iterator<Node, key_value_pair> rhs)
	{
		return (lhs.root() == rhs.root());
	}

	template < typename Node, typename key_value_pair >
	bool	operator!=(const map_iterator<Node, key_value_pair>& lhs, const map_iterator<Node, key_value_pair> rhs)
	{
		return (lhs.root() != rhs.root());
	}

}

#endif