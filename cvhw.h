#include<core\core.hpp>
#include<highgui\highgui.hpp>
#include<vector>
#include<set>
#include<map>

//color define
#define GRAY 128

typedef struct bounding_box
{
	int sum_pixel;
	int top_left_x, top_left_y;
	int bottom_right_x, bottom_right_y;
	int centroid_x, centroid_y;
	bounding_box()
	{
		sum_pixel=0;
		top_left_x = top_left_y = bottom_right_x = bottom_right_y = -1; //null
	}
}BOUNDING_BOX;
class CVHW
{
	cv::Mat image;
	
	void set_pix ( int , int , int  );
	uchar get_pix ( int , int );

	//run-length algorithm varibles
	int runs;
	int* row_start;
	int* row_end;
	int* row;
	int* start_col;
	int* end_col;
	int* perm_label;
	int* label;
	int* next;
	int* eq_class;

	void count_run();
	void initialize_run_table( );
	void make_equivalent(int , int);
	void initialize_equiv();
	void run_length();

	void classic_connected_components( );
public:
	
	CVHW(char*,int flag=0);
	~CVHW();
	cv::Mat get_image();
	void save_work(char*);
	//homework 1
	void upside_down();
	void right_side_left();
	void diagonally_mirrored();
	//homework 2
	void binary(int threshold=128);
	int* histogram();
	void connected_components(int threshold=500);
	void draw_bounding_box ( BOUNDING_BOX& );
};



