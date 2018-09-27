#pragma once
#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song> {
  private:
	Node<Song>* tail_ptr_; // Pointer to last node

  public:
	PlayList();                            // default constructor
	PlayList(const Song& a_song);          // parameterized constructor
	PlayList(const PlayList& a_play_list); // copy constructor
	~PlayList();                           // Destructor

	Node<Song>* getPointerToLastNode() const;
	bool add(const Song& new_song) override;
	void loop();
	void unloop();
	void displayPlayList();
};