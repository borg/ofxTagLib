# ofxTagLib
Shallow wrapper for [TagLib](https://taglib.github.io/)

Only tested for working with MP3s.

Example usage:

```

string artist = "Miles Davis";
string album = "Kind of Blue";
string track = "Blue in Green";

 ofFile file;
 file.open(input+".mp3");
 
 ofxTagLib::setArtist(file.getAbsolutePath(), artist);
 ofxTagLib::setAlbum(file.getAbsolutePath(), album);
 ofxTagLib::setTitle(file.getAbsolutePath(), track);
 
//set convert ofImage to cover image
 ofFile coverImg;
 coverImg.open(currentImg);
 if(coverImg.exists()){
     ofxTagLib::setImage(file.getAbsolutePath(), coverImg.getAbsolutePath());
 }
    
 file.close();
 ```



Andreas Borg

[crea.tion.to](http://crea.tion.to)