// Assignment: CSCI 235, Fall 2018, Project 2
// Name: Marin Pavlinov Marinov
// Date: 09/011/18
// File Name: Song.cpp

#include "Song.h"
#include <iostream>

Song::Song() {}

Song::Song(const std::string& title, const std::string& author, const std::string& album)
{
	title_ = title;

	author_ = author;

	album_ = album;
}

void Song::setTitle(std::string title)
{
	title_ = title;
}

void Song::setAuthor(std::string author)
{
	author_ = author;
}

void Song::setAlbum(std::string album)
{
	album_ = album;
}

std::string Song::getTitle() const
{
	return title_;
}

std::string Song::getAuthor() const
{
	return author_;
}

std::string Song::getAlbum() const
{
	return album_;
}

bool operator==(const Song& lhs, const Song& rhs)
{
	return lhs.getTitle() == rhs.getTitle() && lhs.getAuthor() == rhs.getAuthor()
	       && lhs.getAlbum() == rhs.getAlbum();
}
