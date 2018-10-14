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

PlayList::PlayList(const PlayList& a_play_list) : LinkedSet<Song>(a_play_list) {} // copy constructor

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
	auto curr_ptr = new Node<Song>();
	previous_ptr = head_ptr_;

	while (!found && (previous_ptr != nullptr)) {
	    // check if the target is the head_ptr
	    if (target == previous_ptr->getItem()) {
	        found = true;
	        curr_ptr = previous_ptr;
	    }
		else if (target == previous_ptr->getNext()->getItem()) {
			// end while because target was found
			found = true;
			// make the current pointer the target
			curr_ptr->setNext(previous_ptr->getNext());
			curr_ptr = curr_ptr->getNext();
		}
		else { // keep searching until target is found
			previous_ptr = previous_ptr->getNext();
		}

	} // end while

	return curr_ptr;
}

bool PlayList::remove(const Song& old_song) {
	auto prev_ptr = new Node<Song>();
	// pointer to be deleted
	auto target = getPointerTo(old_song,prev_ptr);
	bool result = true;

	if (!isEmpty() && target != nullptr) {
	    // removing from the beginning
	    if (target == head_ptr_) {
            head_ptr_ = head_ptr_->getNext();
	    } // removing from any other position
	    else {
	        prev_ptr->setNext(target->getNext());
            prev_ptr = prev_ptr->getNext();
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
    auto new_node = new Node<Song> (new_song);
    bool result = true;
    // Adding new node to an EMPTY list
    if (tail_ptr_ == nullptr) {
    	// tail and head are pointing to the same place because there is ONLY ONE song int the playlist
    	head_ptr_ = new_node;
    	tail_ptr_ = head_ptr_;
    	item_count_++;
    }  // Add to non-empty list ONLY if no duplicate is found
    else if (!contains(new_song)) {
    	tail_ptr_->setNext(new_node);
    	tail_ptr_ = tail_ptr_->getNext();
    	item_count_++;
    } // goes here when function is Unable to add a new node
    else {
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
	// loop();
	// Create the vector
	std::vector<Song> song_vector = toVector();

	for (int i = 0; i < getCurrentSize(); i++) {
		std::cout << "* Title: " << song_vector[i].getTitle()
		          << " * Author: " << song_vector[i].getAuthor()
		          << " * Album: " << song_vector[i].getAlbum() << " * " << '\n';
	}

	std::cout << "End of playlist" << '\n';
}