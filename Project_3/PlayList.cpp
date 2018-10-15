// Assignment: CSCI 235, Fall 2018, Project 3
// Name: Marin Pavlinov Marinov
// Date: 09/27/18
// File Name: PlayList.cpp
// This file implements the PlayList class

#include "PlayList.h"
#include <iostream>

// initialization
PlayList::PlayList() : tail_ptr_(nullptr) {}

// parametrized constructor
PlayList::PlayList(const Song& a_song) {
	add(a_song);
}

PlayList::PlayList(const PlayList& a_play_list) : LinkedSet<Song>(a_play_list) {
	tail_ptr_ = getPointerToLastNode();
} // copy constructor

// destructor
PlayList::~PlayList() {
	unloop();
	clear();
}

// get the last point in the chain (Function was not necessary)
Node<Song>* PlayList::getPointerToLastNode() const {
	// Create node and start from the beginning
	auto last_node = head_ptr_;
	// transverse chain till the end
	while (last_node->getNext() != nullptr)
		last_node = last_node->getNext();

	return last_node;
}

// get the specified pointer and preserve order
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
	bool found = false;
	auto target_ptr = new Node<Song>();
	previous_ptr = head_ptr_;

	while (!found && (previous_ptr != nullptr)) {
		// Checking when previous pointer is equal to the head pointer
		if (target == previous_ptr->getItem()) {
			found = true;
			target_ptr = previous_ptr; // previous pointer is already the target
		}                              // General case
		else if (target == previous_ptr->getNext()->getItem()) {
			found = true;
			// make the current pointer the target
			target_ptr->setNext(previous_ptr->getNext());
			target_ptr = target_ptr->getNext();
		} // Keep searching until target is found
		else {
			previous_ptr = previous_ptr->getNext();
		}

	} // end while

	return target_ptr;
}

bool PlayList::remove(const Song& target_song) {
	auto prev_node = new Node<Song>();
	// pointer to be deleted
	auto target_node = getPointerTo(target_song, prev_node);
	bool result = true;

	if (!isEmpty() && target_node != nullptr) {
		// removing from the beginning
		if (target_node == head_ptr_) {
			head_ptr_ = head_ptr_->getNext();
		} // removing from any other position
		else {
			prev_node->setNext(target_node->getNext());
			prev_node = prev_node->getNext();
		}

		item_count_--;
	} // Make false when node cannot be deleted
	else {
		result = false;
	}

	return result;
}

// Adds a song to the playlist from the end
bool PlayList::add(const Song& new_song) {
	// Create a new node
	auto new_node = new Node<Song>(new_song);
	bool result = true;

	if (!contains(new_song)) {
		// Adding new node to an EMPTY list
		if (tail_ptr_ == nullptr) {
			// tail and head are pointing to the same place because there is ONLY ONE song in the
			// playlist
			head_ptr_ = new_node;
			tail_ptr_ = head_ptr_;
		} // Adding node to non-empty list
		else {
			tail_ptr_->setNext(new_node);
			tail_ptr_ = tail_ptr_->getNext();
		}

		item_count_++;
	}
	else { // goes here when function is Unable to add a new node
		result = false;
	}

	return result;
}

// loop to start from the head
void PlayList::loop() {
	tail_ptr_->setNext(head_ptr_);
}

// set things back to null
void PlayList::unloop() {
	tail_ptr_->setNext(nullptr);
}

// displays the title, author, and album
void PlayList::displayPlayList() {
	// Create the vector
	std::vector<Song> song_vector = toVector();

	for (int i = 0; i < getCurrentSize(); i++) {
		std::cout << "* Title: " << song_vector[i].getTitle()
		          << " * Author: " << song_vector[i].getAuthor()
		          << " * Album: " << song_vector[i].getAlbum() << " * " << '\n';
	}

	std::cout << "End of playlist" << '\n';
}