#include <iostream>
#include <string>
#include <cstdlib> // for system()
#include <limits>  // for cin.ignore()

using namespace std;

void downloadVideo(const string& url, const string& quality = "best") {
    // Construct the youtube-dl command
    string command = "youtube-dl -f " + quality + " \"" + url + "\"";
    
    cout << "Downloading video with command: " << command << endl;
    
    // Execute the command
    int result = system(command.c_str());
    
    if (result != 0) {
        cerr << "Error occurred during download. Make sure youtube-dl is installed." << endl;
    }
}

void downloadAudio(const string& url) {
    // Construct the youtube-dl command for audio only
    string command = "youtube-dl -x --audio-format mp3 \"" + url + "\"";
    
    cout << "Downloading audio with command: " << command << endl;
    
    // Execute the command
    int result = system(command.c_str());
    
    if (result != 0) {
        cerr << "Error occurred during download. Make sure youtube-dl is installed." << endl;
    }
}

int main() {
    cout << "YouTube Downloader" << endl;
    cout << "-----------------" << endl;
    
    string url;
    cout << "Enter YouTube URL: ";
    getline(cin, url);
    
    if (url.empty()) {
        cerr << "URL cannot be empty!" << endl;
        return 1;
    }
    
    cout << "\nChoose download option:" << endl;
    cout << "1. Download Video (best quality)" << endl;
    cout << "2. Download Video (720p)" << endl;
    cout << "3. Download Audio (MP3)" << endl;
    cout << "Enter choice (1-3): ";
    
    int choice;
    cin >> choice;
    
    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (choice) {
        case 1:
            downloadVideo(url);
            break;
        case 2:
            downloadVideo(url, "bestvideo[height<=720]+bestaudio/best[height<=720]");
            break;
        case 3:
            downloadAudio(url);
            break;
        default:
            cerr << "Invalid choice!" << endl;
            return 1;
    }
    
    cout << "Download completed (or attempted). Check the current directory for your file." << endl;
    
    return 0;
}