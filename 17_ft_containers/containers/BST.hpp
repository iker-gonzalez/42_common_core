/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 08:31:08 by marvin            #+#    #+#             */
/*   Updated: 2022/12/26 11:43:38 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include "../utils/utility.hpp"

	//?https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
	//?https://www.programiz.com/dsa/binary-search-tree
	//?https://www.programiz.com/dsa/balanced-binary-tree
	//?https://www.programiz.com/dsa/avl-tree

	//*** binary search tree definition***//
	/*
		A binary Search Tree is a node-based binary tree data structure which has the following properties:  

		1) The left subtree of a node contains only nodes with keys lesser than the node’s key.
		2) The right subtree of a node contains only nodes with keys greater than the node’s key.
		3) The left and right subtree each must also be a binary search tree. 
		4) There must be no duplicate nodes.
	*/

	//*** balanced binary search tree***//
	/*
		1) difference between the left and the right subtree for any node is not more than one
		2) the left subtree is balanced
		3) the right subtree is balanced
	*/

	//? https://www.programiz.com/dsa/avl-tree
	//*** AVL Tree ***//
	/*
		AVL tree is a self-balancing binary search tree in which each node maintains extra information called
		a balance factor whose value is either -1, 0 or +1.
	*/


	/*
	*   key_value_pair      Type of keys mapped to elements.
	*   Compare             Comparison object used to sort the binary tree.
	*   Alloc               Object used to manage BST storage.
	*/


namespace ft {
	
	template <typename key_value_pair, typename Compare, typename Allocator> 
	class Bst {
			
		public:
				//********** ***********//
				//**** MEMBER TYPES ****//
				//********** ***********//

				typedef key_value_pair										value_type;
				typedef Compare												key_compare;
				typedef typename Allocator::template rebind<Bst>::other		allocator_type;
				typedef typename std::size_t								size_type;

				//*********** ********** ****//
				//**** MEMBER ATTRIBUTES ****//
				//********** *********** ****//
				
				value_type										data;
				Bst*											left;
				Bst*											right;
				Bst*											parent;
				int												balance;

		private:

				key_compare										_comp;
				allocator_type									_alloc;

		public:
		
				//*********** ********** ****//
				//**** MEMBER FUNCTIONS *****//
				//********** *********** ****//

				//*constructor
				explicit Bst(value_type d = value_type(), const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()): data(d)
				{
					this->left = 0;
					this->right = 0;
					this->parent = 0;
					this->balance = 0;
					this->_comp = comp;
					this->_alloc = alloc;
					return ;
				}

				//*assignment operator
				Bst& operator=(const Bst other)
				{
					this->left = other.left;
					this->right = other.right;
					this->parent = other.parent;
					this->balance = other.balance;
					this->data = other->data;
					return(*this);
				}

				//*destructor
				~Bst () {};

				//*search
				Bst* search(Bst* root, value_type data) const
				{
					if (!root || root->data.first == data.first)
						return (root);
					if (this->_comp(root->data.first, data.first))
						return (search(root->right, data));
					return (search(root->left, data));
				}

				// Insert new node
				Bst*& insert(Bst*& node, value_type data)
				{
					//! Return a new node if the tree is empty
					if (!node)
					{
						node = this->_alloc.allocate(1);
						this->_alloc.construct(node, Bst(data));
						return (node);
					}
				 	// Traverse to the left if data key is smaller than current node's key
					if (this->_comp(data.first, node->data.first))
					{
						node->left = insert(node->left, data);
						node->left->parent = node;
					}
					// Traverse to the right if data key is bigger than current node's key
					else if (data.first != node->data.first)
					{
						node->right = insert(node->right, data);
						node->right->parent = node;
					}
					node->balance = get_balance(node);
					if (node->balance > 1 && this->_comp(data.first, node->left->data.first))
						node = rotateLeftLeft(node);
					else if (node->balance < -1 && this->_comp(node->right->data.first, data.first))
						node = rotateRightRight(node);
					else if (node->balance > 1 && this->_comp(node->left->data.first, data.first))
					{
						node->left = rotateRightRight(node->left);
						node = rotateLeftLeft(node);
					}
					else if (node->balance < -1 && this->_comp(data.first, node->right->data.first))
					{
						node->right = rotateLeftLeft(node->right);
						node = rotateRightRight(node);
					}
					return (node); //returns root
				}

				// Deleting a node
				Bst *deleteNode(Bst *node, value_type data) 
				{
					// Return if the tree is empty
					if (!node)
						return (node);
					//! find the node to be deleted //
					// Traverse to the left if data key is smaller than current node's key
					if (this->_comp(data.first, node->data.first))
						node->left = deleteNode(node->left, data);
					// Traverse to the right if data key is bigger than current node's key
					else if (this->_comp(node->data.first, data.first))
						node->right = deleteNode(node->right, data);
					else 
					{
						//! once the node has been found //
						// If the node is with //! only one child or no child //
						/*
							1) Replace that node with its child node.
							2) Remove the child node from its original position.
						*/
					
						if (node->left == NULL) 
						{
							Bst *temp = node->right;
							if (temp)
								temp->parent = node->parent;
							this->_alloc.destroy(node);
							this->_alloc.deallocate(node, 1);
							return (temp);
						} 
						else if (node->right == NULL) 
						{
							Bst *temp = node->left;
							if (temp)
								temp->parent = node->parent;
							this->_alloc.destroy(node);
							this->_alloc.deallocate(node, 1);
							return (temp);
						}
						else
						{
							// If the node has //! two children //
							
							// 1) Get the inorder successor of that node.
							Bst *succ= get_inorder_successor(node->right);
							
							//2) Establish parent succesor logic
							Bst *parent = node;
							if (parent != node)
								parent->left = succ->right;
							else
								parent->right = succ->right;
							if (succ->right)
								succ->right->parent = parent;

							// 3) Replace the node with the inorder successor.
							node->data = succ->data;

							// 4) Remove the inorder successor from its original position.
							this->_alloc.destroy(succ);
							this->_alloc.deallocate(succ, 1);
							
						}
					}
					node->balance = get_balance(node);
					return (node);
				}

				// Find the inorder successor
				Bst *get_inorder_successor(Bst *node) 
				{
					Bst *current = node;
					// Find the leftmost leaf
					while (current && current->left != NULL)
						current = current->left;
					return current;
				}

				void	clean(Bst** root)
				{
					if (!(*root))
						return ;
					if ((*root)->left)
						clean(&((*root)->left));
					if ((*root)->right)
						clean(&((*root)->right));
					(*root)->left = 0;
					(*root)->right = 0;
					this->_alloc.destroy(*root);
					this->_alloc.deallocate(*root, 1);
					*root = 0;
					return ;
				}

				/** Allocator **/
				allocator_type	get_allocator(void) const
				{
					return (this->_alloc);
				}

				size_type	max_size(void) const
				{
					return (this->_alloc.max_size());
				}

				int		get_height(Bst* root) const
				{
					int	lheight;
					int	rheight;

					if (!root)
						return (-1);
					lheight = get_height(root->left);
					rheight = get_height(root->right);
					if (lheight < rheight)
						return (rheight + 1);
					return (lheight + 1);
				}

				int		get_balance(Bst* root) const
				{
					if (!root)
						return (-1);
					return (get_height(root->left) - get_height(root->right));
				}

				Bst*&	rotateLeftLeft(Bst*& root)
				{
					Bst*	tmp;
					Bst*	tmp_succ;

					tmp = root->left;
					tmp_succ = root;
					root->left = tmp->right;
					if (tmp->right)
						tmp->right->parent = root;
					tmp->right = root;
					tmp->parent = root->parent;
					if (root->parent && root->parent->left == root)
						root->parent->left = tmp;
					else if (root->parent)
						root->parent->right = tmp;
					tmp_succ->parent = tmp;
					return (root);
				}

				Bst*&		rotateRightRight(Bst*& root)
				{
					Bst*	tmp;
					Bst*	tmp_succ;

					tmp = root->right;
					tmp_succ = root;
					root->right = tmp->left;
					if (tmp->left)
						tmp->left->parent = root;
					tmp->left = root;
					tmp->parent = root->parent;
					if (root->parent && root->parent->left == root)
						root->parent->left = tmp;
					else if (root->parent)
						root->parent->right = tmp;
					tmp_succ->parent = tmp;
					return (root);
				}
	};
}

#endif