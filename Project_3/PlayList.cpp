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

PlayList::PlayList(const PlayList& a_play_list) : LinkedSet<Song>(a_play_list) {
	// item_count_ = a_play_list.item_count_;
	// Node<Song>* orig_chain_ptr = a_play_list.tail_ptr_; // Points to nodes in original chain

	// if (orig_chain_ptr == nullptr)
	// 	tail_ptr_ = nullptr; // Original Set is empty
	// else {
	// 	// Copy first node
	// 	tail_ptr_ = new Node<Song>();
	// 	tail_ptr_->setItem(orig_chain_ptr->getItem());

	// 	// Copy remaining nodes
	// 	Node<Song>* new_chain_ptr = tail_ptr_;      // Points to last node in new chain
	// 	orig_chain_ptr = orig_chain_ptr->getNext(); // Advance original-chain pointer

	// 	while (orig_chain_ptr != nullptr) {
	// 		// Get next item from original chain
	// 		Song nextItem = orig_chain_ptr->getItem();

	// 		// Create a new node containing the next item
	// 		Node<Song>* new_node_ptr = new Node<Song>(nextItem);

	// 		// Link new node to end of new chain
	// 		new_chain_ptr->setNext(new_node_ptr);

	// 		// Advance pointer to new last node
	// 		new_chain_ptr = new_chain_ptr->getNext();

	// 		// Advance original-chain pointer
	// 		orig_chain_ptr = orig_chain_ptr->getNext();
	// 	} // end while

	// 	new_chain_ptr->setNext(nullptr); // Flag end of chain
	// }                                    // end if
} // copy constructor

PlayList::~PlayList() {
	unloop();
	clear();
}

Node<Song>* PlayList::getPointerToLastNode() const {
	return tail_ptr_;
}

Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
	bool found = false;
	Node<Song>* cur_ptr = new Node<Song>();
	previous_ptr = head_ptr_;

	while (!found && (head_ptr_ != nullptr)) {
		if (target == previous_ptr->getNext()->getItem()) {
			found = true;
			cur_ptr->setNext(previous_ptr);
			cur_ptr = cur_ptr->getNext();
		}
		else
			previous_ptr = previous_ptr->getNext();
	} // end while

	return cur_ptr;
}

bool PlayList::remove(const Song& old_song) {
	Node<Song>* prev_ptr = new Node<Song>();
	Node<Song>* cur_ptr = getPointerTo(old_song, prev_ptr);

	if (!isEmpty() && cur_ptr != nullptr) {
		Node<Song>* node_to_delete_ptr = new Node<Song>();
		node_to_delete_ptr->setNext(cur_ptr);
		node_to_delete_ptr = node_to_delete_ptr->getNext();

		// deleting
		node_to_delete_ptr->setNext(nullptr);
		delete node_to_delete_ptr;
		node_to_delete_ptr = nullptr;

		item_count_--;
		return true;
	}

	return false;
}

// FIX THIS
bool PlayList::add(const Song& new_song) {
	if (!(contains(new_song))) {
		Node<Song>* next_node_ptr = new Node<Song>();
		next_node_ptr->setItem(new_song);
		next_node_ptr->setNext(nullptr);

		// New node points to chain
		// SEG FAULTS BELOW
		tail_ptr_->setNext(next_node_ptr);
		tail_ptr_ = tail_ptr_->getNext();
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
	// loop();
	std::vector<Song> song_vector = toVector();

	for (int i = 0; i < getCurrentSize(); i++) {
		std::cout << "* Title: " << song_vector[i].getTitle()
		          << " * Author: " << song_vector[i].getAuthor()
		          << " * Album: " << song_vector[i].getAlbum() << " * " << '\n';
	}

	std::cout << "End of playlist" << '\n';
}