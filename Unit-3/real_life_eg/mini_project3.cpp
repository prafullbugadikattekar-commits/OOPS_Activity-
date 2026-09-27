#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Real-world Mini Project 3: Multimedia Player & Playlist System
// Abstract base class
class Media {
protected:
    string title;
    string format;

public:
    Media(string t, string f) : title(t), format(f) {}

    // Pure virtual functions (= 0): interface requiring playback controls for every media format
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void showDetails() const = 0;

    // Virtual destructor enables safe cleanup through polymorphic pointers
    virtual ~Media() = default;
};

class Audio : public Media {
private:
    int bitrateKbps;

public:
    Audio(string t, string f, int bitrate)
        : Media(t, f), bitrateKbps(bitrate) {}

    // override keyword: provides Audio-specific implementation of playback methods
    void play() override {
        cout << "Playing Audio track: " << title << " [" << format << "]" << endl;
    }

    void pause() override {
        cout << "Paused Audio track: " << title << endl;
    }

    void stop() override {
        cout << "Stopped Audio track: " << title << endl;
    }

    void showDetails() const override {
        cout << "Audio | Title: " << title << " | Format: " << format << " | Bitrate: " << bitrateKbps << " kbps" << endl;
    }
};

class Video : public Media {
private:
    string resolution;

public:
    Video(string t, string f, string res)
        : Media(t, f), resolution(res) {}

    // Overriding playback controls for Video stream
    void play() override {
        cout << "Playing Video stream: " << title << " in " << resolution << endl;
    }

    void pause() override {
        cout << "Paused Video stream: " << title << endl;
    }

    void stop() override {
        cout << "Stopped Video stream: " << title << endl;
    }

    void showDetails() const override {
        cout << "Video | Title: " << title << " | Format: " << format << " | Resolution: " << resolution << endl;
    }
};

class Image : public Media {
private:
    string dimensions;

public:
    Image(string t, string f, string dim)
        : Media(t, f), dimensions(dim) {}

    // Overriding playback controls for static Image display
    void play() override {
        cout << "Displaying Image: " << title << " (" << dimensions << ")" << endl;
    }

    void pause() override {
        cout << "Image display paused." << endl;
    }

    void stop() override {
        cout << "Closed Image viewer for: " << title << endl;
    }

    void showDetails() const override {
        cout << "Image | Title: " << title << " | Format: " << format << " | Dimensions: " << dimensions << endl;
    }
};

int main() {
    // Vector of unique_ptr to abstract base class Media (polymorphic container)
    vector<unique_ptr<Media>> playlist;

    // Instantiating derived objects inside smart pointers
    playlist.push_back(make_unique<Audio>("Song_01", "MP3", 320));
    playlist.push_back(make_unique<Video>("Movie_Trailer", "MP4", "1080p"));
    playlist.push_back(make_unique<Image>("Vacation_Photo", "PNG", "3840x2160"));

    cout << "================ MEDIA PLAYLIST DETAILS ================" << endl;
    // Range-based for loop using const reference (&): prevents copying unique_ptr
    for (const auto& item : playlist) {
        // Dynamic binding: calls correct derived showDetails() at runtime
        item->showDetails();
    }

    cout << "\n================ CONTROLLING MEDIA ================" << endl;
    for (const auto& item : playlist) {
        // Dynamic dispatch for playback actions
        item->play();
        item->pause();
        item->stop();
        cout << "------------------------------------" << endl;
    }

    return 0;
}
