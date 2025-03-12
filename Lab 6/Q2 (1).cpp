#include <iostream>

using namespace std;

class MediaFile {
    protected:
        string filePath;
        double size;

    public:
        MediaFile(string f, double s) : filePath(f), size(s) {}

        virtual void play() {
            cout << "Playing..." << endl;
        }

        virtual void stop() {
            cout << "Stopping..." << endl;
        }

        virtual void showInfo() {
            cout << "File Path: " << filePath << endl;
            cout << "Size: " << size << endl;
        }

};

class VisualMedia : virtual public MediaFile {
    protected:
        int resolutionWidth;
        int resolutionHeight;

    public:
        VisualMedia(string f, double s, int rw, int rh) : MediaFile(f, s), resolutionWidth(rw), resolutionHeight(rh) {}

};

class AudioMedia : virtual public MediaFile {
    protected:
        int sampleRate;

    public:
        AudioMedia(string f, double s, int sr) : MediaFile(f, s), sampleRate(sr) {}
        
};

class VideoFile : virtual public VisualMedia, virtual public AudioMedia {
    public:
        VideoFile(string f, double s, int rw, int rh, int sr) : MediaFile(f, s), VisualMedia(f, s, rw, rh), AudioMedia(f, s, sr) {}

        void play() override { // MediaFile functionality + new
            MediaFile::play();
            cout << "Playing Video File" << endl;
        }

        void stop() override { // Completely override
            cout << "Stopping Video File" << endl;
        }

        void showInfo() override {
            MediaFile::showInfo();
            cout << "Resolution: " << resolutionWidth << " x " << resolutionHeight << endl;
            cout << "Sample Rate: " << sampleRate << endl;
        }

};

class AudioFile : public AudioMedia {
    public:
        AudioFile(string f, double s, int sr) : MediaFile(f, s), AudioMedia(f, s, sr) {}

        void play() override { // MediaFile functionality + new
            MediaFile::play();
            cout << "Playing Audio File" << endl;
        }

        void stop() override { // Only MediaFile functionality
            AudioMedia::stop();
        }

        void showInfo() override {
            MediaFile::showInfo();
            cout << "Sample Rate: " << sampleRate << endl;
        }

};

class ImageFile : public VisualMedia {
    public:
        ImageFile(string f, double s, int rw, int rh) : MediaFile(f, s), VisualMedia(f, s, rw, rh) {}

        void play() override { // Completely override 
            cout << "Playing Audio File" << endl;
        }

        void stop() override { // Completely override
            cout << "Stopping Audio File" << endl;
        }

        void showInfo() override {
            MediaFile::showInfo();
            cout << "Resolution: " << resolutionWidth << " x " << resolutionHeight << endl;
        }

};

int main() {
    VideoFile v("Desktop", 256, 1020, 980, 20);
    AudioFile a("Documents", 128, 30);
    ImageFile i("Downloads", 448, 1020, 980);

    MediaFile* video = &v;
    MediaFile* audio = &a;
    MediaFile* image = &i;

    video->showInfo();
    video->play();
    video->stop();
    
    audio->showInfo();
    audio->play();
    audio->stop();
    
    image->showInfo();
    image->play();
    image->stop();
    
    return 0;
}