#include <iostream>
#include <string>

class PlayList
{
  public:
	PlayList();

	PlayList(const Song& a_song);
	int getNumberOfSongs() const;

	bool isEmpty() const;

	bool addSong(const Song& new_song);

	bool removeSong(const Song& a_song);

	void clearPlayList();

	void displayPlayList() const;

  private:
	// playlist_
};
