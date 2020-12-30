//#include "PlayOgg.h"

#include <sstream>

#include "../global.h"

#include "hsound.h"
#include "../../lib/xsound/ogg_stream.h"

extern clunk::Context context;
//static MpegSound* music = 0;
//extern LPDIRECTSOUND lpDS;

static int curTrack = 2;
static int volume = 128;

const char* getTrackPathName(int track) {
	switch (track) {
		case 1:	
			return "resource/music/FUCKILOSTMYRUBBOX.ogg";
		case 2:	
			return "resource/music/GORBS.ogg";
		case 3:	
			return "resource/music/INFERNALDISCO.ogg";
		case 4:	
			return "resource/music/IWANNARIDEMYMOGGY.ogg";
		case 5:	
			return "resource/music/FOSTRALLER.ogg";
		case 6:	
			return "resource/music/MOREBEEBS.ogg";
		case 7:	
			return "resource/music/OUTRO.ogg";
		case 8:	
			return "resource/music/THATTABUTASKAGAIN.ogg";
		default: 
			return "resource/music/MOGGYWAVES.ogg";
	}
}

void xsInitMusic(void) {
	//MpegInitLibrary(lpDS);
//	music = new MpegSound();
//	music->SetVolume(255);
}

void xsDeInitMusic(void) {
//	music->Stop();
//	delete music;
	//if (music)
	//	{
		//Mix_FreeMusic(music);
	//	music = NULL;
	//	}
	//MpegDeinitLibrary();
}

void xsPlayMusic(int track,int min = 0,int sec = 0) {
	curTrack = track;
	//music->OpenToPlay(getTrackPathName(track));
	//music=Mix_LoadMUS(getTrackPathName(track));
	//Mix_PlayMusic(music, 31);
	//std::cout<<"xsPlayMusic:"<<curTrack<<std::endl;
	context.play(-1, new OggStream(getTrackPathName(track)), true);
	context.set_volume(-1, volume/256.0);
}

void xsPlayOneTrackMusic(int track,int min = 0,int sec = 0) {
	curTrack = track;
	//if (music)
	//	{
		//Mix_HaltMusic();
		//Mix_RewindMusic();
		//Mix_FreeMusic(music);
		//music = NULL;
		//}
	//music=Mix_LoadMUS(getTrackPathName(track));
	//Mix_RewindMusic();
	//Mix_PlayMusic(music, 31);
	//music->OpenToPlay(getTrackPathName(track));
	//std::cout<<"xsPlayOneTrackMusic:"<<curTrack<<std::endl;
	if (context.playing(-1))
		context.stop(-1);
	context.play(-1, new OggStream(getTrackPathName(track)), true);
	context.set_volume(-1, volume/256.0);
}

void xsStopMusic(void) {
	//music->Stop();
	//Mix_HaltMusic();
	if (context.playing(-1))
		context.stop(-1);

}

void xsStopMusic(int &track) {
	track = curTrack;
	xsStopMusic();
}

void xsPauseMusic(void) {
	//music->Pause();
	//Mix_PausedMusic();
	context.pause(-1);
}

void xsResumeMusic(void) {
	//music->Resume();
	//Mix_ResumeMusic();
	context.pause(-1);
}

int xsGetStatusMusic(void) {
	/*switch (music->IsPlay()) {
		case MPEG_STOP:
			return XCD_STOPPED;
		case MPEG_PAUSE:
			return XCD_PAUSED;
		case MPEG_PLAY:
			return XCD_PLAYING;
		default:
			return XCD_OTHER;
	}*/
	if (context.playing(-1)) {
		return XCD_PLAYING;
	} else {
		return XCD_STOPPED;
	}
	return XCD_OTHER;
}

int xsGetCurTrackMusic(void) {
	return curTrack;
}

int xsGetNumTracksMusic(void) {
	return 0;
}

int xsGetTrackLenMusic(int track) {
	return 0;
}

/* ------------------- Volume Management ------------------- */

void xsMixerOpenMusic(void) {
}

int xsGetVolumeMusic(void) {
	//return music->GetVolume();
	return volume;
}

void xsSetVolumeMusic(int val) {
	//std::cout<<"xsSetVolumeMusic:"<<val<<std::endl;
	//music->SetVolume(val);
	float f_val = val;
	f_val/=256;
	//Mix_VolumeMusic(val);
	context.set_volume(-1, f_val);
	volume=val;
}


