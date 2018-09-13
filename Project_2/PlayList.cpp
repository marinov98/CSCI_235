// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: PlayList.cpp

#include "PlayList.h"
#include "Song.h"
#include <iostream>
#include <vector>

PlayList::PlayList() {}

PlayList::PlayList(const Song& a_song)
{
	addSong(a_song);
}

int PlayList::getNumberOfSongs() const
{
	return playlist_.getCurrentSize();
}

bool PlayList::isEmpty() const
{
	return playlist_.isEmpty();
}

bool PlayList::addSong(const Song& new_song)
{
	return playlist_.add(new_song);
}

bool PlayList::removeSong(const Song& a_song)
{
	return playlist_.remove(a_song);
}

void PlayList::clearPlayList()
{
	playlist_.clear();
}

void PlayList::displayPlayList() const
{
	std::vector<Song> playlist = playlist_.toVector();

	for (int i = 0; i < playlist_.getCurrentSize(); i++)
	{
		std::cout << "Title: " << playlist[i].getTitle() << '\n';
		std::cout << "Author: " << playlist[i].getAuthor() << '\n';
	}
}
