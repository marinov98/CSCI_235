// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: Song.cpp

#include "Song.h"
#include <iostream>

Song::Song() {}
// Initialize title, author, and album
Song::Song(const std::string& title, const std::string& author, const std::string& album)
{
	title_ = title;
	author_ = author;
	album_ = album;
}

// set the title name
void Song::setTitle(std::string title)
{
	title_ = title;
}

// set the author name
void Song::setAuthor(std::string author)
{
	author_ = author;
}

// set the album name
void Song::setAlbum(std::string album)
{
	album_ = album;
}

// Return the title
std::string Song::getTitle() const
{
	return title_;
}

// Return the author
std::string Song::getAuthor() const
{
	return author_;
}

// Return the album
std::string Song::getAlbum() const
{
	return album_;
}

// Check if it's the same song
bool operator==(const Song& lhs, const Song& rhs)
{
	return lhs.getTitle() == rhs.getTitle() && lhs.getAuthor() == rhs.getAuthor()
	       && lhs.getAlbum() == rhs.getAlbum();
}
