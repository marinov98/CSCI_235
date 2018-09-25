// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: PlayList.h
#pragma once
#include "Set.h"
#include "Song.h"
#include <iostream>
#include <string>

class PlayList {
  public:
	// Constructors
	PlayList();
	PlayList(const Song& a_song);
	// Functions
	int getNumberOfSongs() const;
	// Checkers
	bool isEmpty() const;
	bool addSong(const Song& new_song);
	bool removeSong(const Song& a_song);
	// voids
	void clearPlayList();
	void displayPlayList() const;

  private:
	Set<Song> playlist_;
};
