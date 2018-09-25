// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: PlayList.cpp

#include "PlayList.h"
#include "Song.h"
#include <iostream>
#include <vector>

PlayList::PlayList() {}

// Add a song in the constructor
PlayList::PlayList(const Song& a_song) {
	addSong(a_song);
}

// Get the number of songs in the playlist
int PlayList::getNumberOfSongs() const {
	return playlist_.getCurrentSize();
}

// Checks if the playlist is empty
bool PlayList::isEmpty() const {
	return playlist_.isEmpty();
}

// Adds a song to the playlist
bool PlayList::addSong(const Song& new_song) {
	return playlist_.add(new_song);
}

// Removes a song from the playlist
bool PlayList::removeSong(const Song& a_song) {
	return playlist_.remove(a_song);
}

// Clears the playlist
void PlayList::clearPlayList() {
	playlist_.clear();
}

// Displays the playlist with the title and the author's name
void PlayList::displayPlayList() const {
	std::vector<Song> playlist = playlist_.toVector();

	for (int i = 0; i < playlist_.getCurrentSize(); i++) {
		std::cout << "* Title: " << playlist[i].getTitle()
		          << " * Author: " << playlist[i].getAuthor()
		          << " * Album: " << playlist[i].getAlbum() << " * " << '\n';
	}
	std::cout << "End of playlist" << '\n';
}
