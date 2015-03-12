/*
 *  ofxTagLib.h
 *  essentia
 *
 *  Created by Andreas Borg on 01/03/2015
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */

//Note that the two .tcc files in the include folder seems to be required to exist but not to be included in xcode

#ifndef _ofxTagLib
#define _ofxTagLib

#include "ofMain.h"

//taglib
#include "taglib.h"
#include "fileref.h"

#include <mpegfile.h>
#include <attachedpictureframe.h>
#include <id3v2tag.h>
#include <mp4file.h>
#include <mp4tag.h>
#include <mp4coverart.h>
#include <vorbisfile.h>
#include <xiphcomment.h>
#include <flacpicture.h>


//#include "base64.h"

namespace TagLib{
class ImageFile : public TagLib::File
{
public:
    ImageFile(const char *file) : TagLib::File(file)
    {
        
    }
    TagLib::ByteVector data()
    {
        return readBlock(length());
    }

    
private:
    virtual TagLib::Tag *tag() const { return 0; }
    virtual TagLib::AudioProperties *audioProperties() const { return 0; }
    virtual bool save() { return false; }
};
    
    };

class ofxTagLib {
	
  public:
    static string getArtist(string mp3){
        ofFile mp3file;
        mp3file.open(mp3);
        
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        TagLib::String str = f.tag()->artist();
        return str.to8Bit();
    };
	static void setArtist(string mp3, string name){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
       
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        f.tag()->setArtist(name.c_str());
        f.save();
    }
    
    static string getAlbum(string mp3){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        TagLib::String str = f.tag()->album();
        return str.to8Bit();

    };
    static void setAlbum(string mp3, string name){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        f.tag()->setAlbum(name);
        f.save();
    }
    
    static string getTitle(string mp3){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        TagLib::String str = f.tag()->title();
        return str.to8Bit();
        
    };
    static void setTitle(string mp3, string name){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        f.tag()->setTitle(name);
        f.save();
    }
    
    static uint getYear(string mp3){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return 0;
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        TagLib::uint yr = f.tag()->year();
        return yr;
        
    };
    static void setYear(string mp3, uint yr){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return 0;
        }
        string nm = mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        f.tag()->setYear(yr);
        f.save();
    }
    
    static string getGenre(string mp3){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        TagLib::String str = f.tag()->genre();
        return str.to8Bit();
        
    };
    static void setGenre(string mp3, string name){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        f.tag()->setGenre(name);
        f.save();
        
    }
    
    static string getComment(string mp3){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        TagLib::String str = f.tag()->comment();
        return str.to8Bit();
        
    };
    static void setComment(string mp3, string name){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        TagLib::FileRef f(nm.c_str());
        f.tag()->setComment(name);
        f.save();
    }
    
    /*
    static string getImage(string mp3){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return "";
        }
        string nm =  mp3file.getAbsolutePath();
        mp3file.close();
        
        TagLib::FileRef f(nm.c_str());
        TagLib::String str = f.tag()->comment();
        return str.to8Bit();
        
    };*/
    
    
    static void setImage(string mp3, string img){
        ofFile mp3file;
        mp3file.open(mp3);
        if(!mp3file.exists()){
            ofLog()<<"[ofxTagLib] "<<mp3<<" does not exist"<<endl;
            return;
        }
        string nm =  mp3file.getAbsolutePath();
        string fileType = ofToUpper(mp3file.getExtension());
       
        mp3file.close();
        
        
        ofFile imgFile;
        imgFile.open(img);
        if(!imgFile.exists()){
            ofLog()<<"[ofxTagLib] "<<img<<" does not exist"<<endl;
            return;
        }
        string imgNm =  imgFile.getAbsolutePath();
        imgFile.close();
        
        TagLib::ImageFile imageFile(imgNm.c_str());
        TagLib::ByteVector imageData = imageFile.data();
        
        
        
        if (fileType == "M4A")
        {
            // read the image file
            TagLib::MP4::CoverArt coverArt((TagLib::MP4::CoverArt::Format) 0x0D, imageData);
            // read the mp4 file
            TagLib::MP4::File audioFile(nm.c_str());
            // get the tag ptr
            TagLib::MP4::Tag *tag = audioFile.tag();
            // get the items map
            TagLib::MP4::ItemListMap itemsListMap = tag->itemListMap();
            // create cover art list
            TagLib::MP4::CoverArtList coverArtList;
            // append instance
            coverArtList.append(coverArt);
            // convert to item
            TagLib::MP4::Item coverItem(coverArtList);
            // add item to map
            itemsListMap.insert("covr", coverItem);
            tag->save();
        }
        else if (fileType == "MP3")
        {
            TagLib::MPEG::File audioFile(nm.c_str());
            
            TagLib::ID3v2::Tag *tag = audioFile.ID3v2Tag(true);
            TagLib::ID3v2::AttachedPictureFrame *frame = new TagLib::ID3v2::AttachedPictureFrame;
            
            frame->setMimeType("image/jpeg");
            frame->setPicture(imageData);
            
            tag->addFrame(frame);
            audioFile.save();
            
        }
        else if (fileType == "OGG")
        {
            
            /*
             
             //ADD B64 is needed
            TagLib::Ogg::Vorbis::File audioFile(nm.c_str());
            TagLib::Ogg::XiphComment *tag = audioFile.tag();
            
            TagLib::FLAC::Picture* picture = new TagLib::FLAC::Picture();
            picture->setData(imageData);
            picture->setType((TagLib::FLAC::Picture::Type) 0x03); // FrontCover
            picture->setMimeType("image/jpeg");
            picture->setDescription("Front Cover");
            TagLib::ByteVector block = picture->render();
            tag->addField("METADATA_BLOCK_PICTURE", b64_encode(block.data(), block.size()), true);
            
            block = imageData;
            tag->addField("COVERART", b64_encode(block.data(), block.size()), true);
            audioFile.save();
             */
        }
        else
        {
            ofLog() << fileType << " is unsupported." << std::endl;
        }
        
                
      
    }
};

#endif
