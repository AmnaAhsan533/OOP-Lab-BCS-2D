#include<iostream>
using namespace std;

class MediaFile{
    protected:
    string file_path;
    double size;
    public:
    MediaFile(string path, double s): file_path(path), size(s) {}
    virtual void Play() = 0;
    virtual void Stop() = 0;
    virtual ~MediaFile() {}
};

class VisualMedia: virtual public MediaFile{
    protected:
    string resolution;
    public:
    VisualMedia(string path, double s, string res): MediaFile(path, s), resolution(res) {}
    void showInfo() {
        cout << "Resolution: " << resolution << endl;
    }
};

class AudioMedia: virtual public MediaFile{
    protected:
    int sample_rate;
    public:
    AudioMedia(string path, double s, int sr): MediaFile(path, s), sample_rate(sr) {}
    void showAudioInfo() {
        cout << "Sample Rate: " << sample_rate << " Hz" <<endl;
    }
};

class VideoFile: public AudioMedia, public VisualMedia{
    public:
    VideoFile(string path, double s, string res, int rate): MediaFile(path, s), VisualMedia(path, s, res), AudioMedia(path, s, rate) {}

    void Play() override {
        std::cout << "Playing video file: " << file_path << endl;
        showInfo(); 
        showAudioInfo(); 
    }
    void Stop() override {
        cout << "Stopping video playback." << endl;
    }
};

int main() {
    MediaFile* files[] = {
        new VideoFile("movie.mp4", 700, "1920x1080", 48000)
    };

    std::cout << "\n Playing Media Files\n";
    for (MediaFile* file : files) {
        file->Play();
        std::cout << "--------------------\n";
    }

    std::cout << "\n Stopping Media Files\n";
    for (MediaFile* file : files) {
        file->Stop();
        std::cout << "--------------------\n";
    }

    for (MediaFile* file : files) {
        delete file;
    }

    return 0;
}