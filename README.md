# Triangulate

JNI wrapper of John W. Ratcliff's Triangulate library.

* [Triangulate Homepage] (http://www.flipcode.com/archives/Efficient_Polygon_Triangulation.shtml)


## Usage

	package fr.myrddin.triangulate;
	
	Triangulate triangulator = new Triangulate();

	int[] sp = { 325, 272, 118, 272, 118, 98, 325, 98 };

	int[] polygon = triangulator.triangulate(sp);

	for (int i = 0; i < polygon.length; i++)
	{
		Log.e("", "" + polygon[i]);
		Log.e("", "----");
	}