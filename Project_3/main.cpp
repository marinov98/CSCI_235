#include "PlayList.h"
#include "Song.h"
#include <iostream>

int main() {
	// Test PlayList

	std::cout << "**** Testing Song class **** \n\n";

	Song song1;

	song1.setTitle("song1");

	song1.setAuthor("author1");

	song1.setAlbum("album1");

	Song song2("song2", "author2", "album2");

	Song song3("song3", "author3", "album3");

	Song song4("song4", "author4", "album4");

	Song song5("song5", "author5", "album5");

	std::cout << "The third song is: ";

	std::cout << song3.getTitle() << ", " << song3.getAuthor() << ", "
	          << song3.getAlbum(); //**2 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\n\n**** Testing PlayList class **** \n";

	std::cout << "\nAdd songs to PlayList, check adding to end of chain and no duplicates allowed: "
	             "\n";

	PlayList playlist1(song1);

	std::cout << playlist1.add(song2);

	playlist1.add(song3);

	playlist1.add(song1);

	playlist1.add(song2);

	playlist1.add(song3);

	std::vector<Song> song_vector = playlist1.toVector();

	playlist1.displayPlayList(); //**10 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\n\nAdd remaining songs\n";

	playlist1.add(song4);

	playlist1.add(song5);

	playlist1.displayPlayList(); //**2 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\n\nTest removing songs from PlayList, check that order is preserved\n";

	std::cout << "\nRemove from the middle\n";

	playlist1.remove(song3);

	playlist1.displayPlayList(); //**10 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\nRemove first song\n";

	playlist1.remove(song1);

	playlist1.displayPlayList(); //**10 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\nRemove last song\n";

	playlist1.remove(song5);

	playlist1.displayPlayList(); //**10 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\n\nTest copy constructor\n";

	PlayList playlist2 = playlist1;

	std::cout << "\nPrinting playlist2 \n";

	playlist2.displayPlayList(); //**8 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\nAdd song to copied playlist\n";

	playlist2.add(song1);

	playlist2.displayPlayList(); //**5 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\nRemove last song from copied playlist\n";

	playlist2.remove(song1);

	playlist2.displayPlayList(); //**5 POINTS FOR CORRECT OUTPUT HERE**

	std::cout << "\nRemove first song from copied playlist\n";

	playlist2.remove(song2);

	playlist2.displayPlayList(); //**5 POINTS FOR CORRECT OUTPUT HERE**

	return 0;
}
