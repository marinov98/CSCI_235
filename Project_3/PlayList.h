// Assignment: CSCI 235, Fall 2018, Project 3
// Name: Marin Pavlinov Marinov
// Date: 09/27/18
// File Name: PlayList.h

#pragma once
#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song> {
  private:
	Node<Song>* tail_ptr_; // Pointer to last node
	Node<Song>* getPointerToLastNode() const;
	Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;

  public:
	PlayList();                            // default constructor
	PlayList(const Song& a_song);          // parameterized constructor
	PlayList(const PlayList& a_play_list); // copy constructor
	~PlayList();                           // Destructor

	bool add(const Song& new_song) override;
	bool remove(const Song& old_song) override;
	void loop();
	void unloop();
	void displayPlayList();
};