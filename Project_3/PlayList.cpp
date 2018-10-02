// Assignment: CSCI 235, Fall 2018, Project 3
// Name: Marin Pavlinov Marinov
// Date: 09/27/18
// File Name: PlayList.cpp
// This file implements the PlayList class

#include "PlayList.h"
#include <iostream>

PlayList::PlayList() : tail_ptr_(nullptr) {}

PlayList::PlayList(const Song& a_song) {
	add(a_song);
}

PlayList::PlayList(const PlayList& a_play_list) /*:LinkedSet<Song>(a_play_list)*/ {
	item_count_ = a_play_list.item_count_;
	Node<Song>* orig_chain_ptr = a_play_list.head_ptr_; // Points to nodes in original chain

	if (orig_chain_ptr == nullptr)
		head_ptr_ = nullptr; // Original Set is empty
	else {
		// Copy first node
		head_ptr_ = new Node<Song>();
		head_ptr_->setItem(orig_chain_ptr->getItem());

		// Copy remaining nodes
		Node<Song>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
		orig_chain_ptr = orig_chain_ptr->getNext(); // Advance original-chain pointer

		while (orig_chain_ptr != nullptr) {
			// Get next item from original chain
			Song nextItem = orig_chain_ptr->getItem();

			// Create a new node containing the next item
			Node<Song>* new_node_ptr = new Node<Song>(nextItem);

			// Link new node to end of new chain
			new_chain_ptr->setNext(new_node_ptr);

			// Advance pointer to new last node
			new_chain_ptr = new_chain_ptr->getNext();

			// Advance original-chain pointer
			orig_chain_ptr = orig_chain_ptr->getNext();
		} // end while

		new_chain_ptr->setNext(nullptr); // Flag end of chain
	}                                    // end if
} // copy constructor

PlayList::~PlayList() {
	unloop();
	clear();
}

Node<Song>* PlayList::getPointerToLastNode() const {
	return tail_ptr_;
}
// FIX THIS
bool PlayList::add(const Song& new_song) {
	if (!(contains(new_song))) {
		Node<Song>* next_node_ptr = new Node<Song>();
		next_node_ptr->setItem(new_song);
		next_node_ptr->setNext(tail_ptr_); // New node points to chain

		tail_ptr_ = next_node_ptr; // New node is now first node
		item_count_++;

		return true;
	}

	return false;
}

void PlayList::loop() {
	tail_ptr_->setNext(head_ptr_);
}

void PlayList::unloop() {
	tail_ptr_->setNext(nullptr);
}

void PlayList::displayPlayList() {
	Node<Song>* cur_ptr = head_ptr_;

	for (int i = 0; i < item_count_; i++) {
		std::cout << "* Title: " << cur_ptr->getItem().getTitle()
		          << " * Author: " << cur_ptr->getItem().getAuthor()
		          << " * Album: " << cur_ptr->getItem().getAlbum() << " * " << '\n';
		// get the next item to print to the user
		cur_ptr->getNext();
	}
	std::cout << "End of playlist" << '\n';
}