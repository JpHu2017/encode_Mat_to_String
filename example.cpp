#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat img = imread(argv[1], CV_LOAD_IMAGE_COLOR); //CV_LOAD_IMAGE_GRAYSCALE
	const string encoding = argv[2]; //图片格式
	vector<uchar> buf;
	cv::imencode("."+encoding, img, buf);
	// Mat转为string,可用做数据保存
	string data = string(reinterpret_cast<char*>(&buf[0]),buf.size());
	imshow("Origin", img);
	cout << data << endl;
	//
	vector<char> vec_data(data.c_str(), data.c_str()+data.size());
	Mat imgRes;
    imgRes = cv::imdecode(vec_data, CV_LOAD_IMAGE_COLOR); //CV_LOAD_IMAGE_GRAYSCALE
	imshow("Result", imgRes);
    // ESC key
    if(waitKey(0) == 27)
    {
        return 0;
    }

	return 0;
}
