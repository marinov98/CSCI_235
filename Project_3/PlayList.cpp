// Assignment: CSCI 235, Fall 2018, Project 3
// Name: Marin Pavlinov Marinov
// Date: 09/27/18
// File Name: PlayList.cpp
// This file implements the PlayList class

#include "PlayList.h"
#include <iostream>

// initialization
PlayList::PlayList() : tail_ptr_(nullptr) {}

// parametarized constructor
PlayList::PlayList(const Song& a_song) {
	add(a_song);
}

PlayList::PlayList(const PlayList& a_play_list) :
    LinkedSet<Song>(a_play_list) {} // copy constructor

// destructor
PlayList::~PlayList() {
	unloop();
	clear();
}

// get the last point in the chain
Node<Song>* PlayList::getPointerToLastNode() const {
	return tail_ptr_;
}

// get the specified pointer and preserve order
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const {
	bool found = false;
	Node<Song>* cur_ptr = new Node<Song>();
	previous_ptr = head_ptr_;

	while (!found && (previous_ptr != nullptr)) {
		if (target == previous_ptr->getNext()->getItem()) {
			// end while
			found = true;
			// make the current pointer the target
			cur_ptr->setNext(previous_ptr);
			cur_ptr = cur_ptr->getNext();
		}
		// keep searching until target is found
		else {
			previous_ptr = previous_ptr->getNext();
		}

	} // end while

	return cur_ptr;
}
// SOME KIND OF SEG FAULT HERE
// POTENTIAL PROBLEM IN getPointTo function
bool PlayList::remove(const Song& old_song) {
	Node<Song>* prev_ptr = new Node<Song>();
	Node<Song>* target_ptr = getPointerTo(old_song, prev_ptr);
	std::cout << "HERE" << target_ptr << std::endl;

	if (!isEmpty() && target_ptr != nullptr) {
		// check for target being at the end of the chain
		if (target_ptr == tail_ptr_) {
			prev_ptr->setNext(nullptr);
			delete target_ptr;
			target_ptr = nullptr;
		}
		// check for target being in the front of the chain
		else if (target_ptr == head_ptr_) {
			Node<Song>* temp_ptr = head_ptr_;
			head_ptr_ = head_ptr_->getNext();
			delete temp_ptr;
			temp_ptr = nullptr;
		}
		// check for general case
		else {
			prev_ptr = target_ptr->getNext();
			delete target_ptr;
			target_ptr = nullptr;
		}

		item_count_--;
		return true;
	}

	return false;
}

// Adds a song to the playlist
bool PlayList::add(const Song& new_song) {
	// CHECK: if list is empty
	if (!tail_ptr_) {
		Node<Song>* next_node_ptr = new Node<Song>();
		tail_ptr_ = next_node_ptr;
		head_ptr_ = next_node_ptr;
		// there is now one item in the playlist
		item_count_ = 1;
	}
	// CHECK: for duplicates
	if (!(contains(new_song))) {
		Node<Song>* next_node_ptr = new Node<Song>();
		// point to the specified item
		next_node_ptr->setItem(new_song);
		// set to null to mark an end to the chain
		next_node_ptr->setNext(nullptr);

		// transfer memory address to the tail
		tail_ptr_->setNext(next_node_ptr);
		tail_ptr_ = tail_ptr_->getNext();
		item_count_++;

		return true;
	}

	return false;
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
	// loop();
	std::vector<Song> song_vector = toVector();

	for (int i = 0; i < getCurrentSize(); i++) {
		std::cout << "* Title: " << song_vector[i].getTitle()
		          << " * Author: " << song_vector[i].getAuthor()
		          << " * Album: " << song_vector[i].getAlbum() << " * " << '\n';
	}

	std::cout << "End of playlist" << '\n';
}