package fr.myrddin.triangulate;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class Jni_triangulateActivity extends Activity
{
	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		Triangulate triangulator = new Triangulate();

		int[] sp = { 325, 272, 118, 272, 118, 98, 325, 98 };

		int[] polygon = triangulator.triangulate(sp);

		for (int i = 0; i < polygon.length; i++)
		{
			Log.e("", "" + polygon[i]);
			Log.e("", "----");
		}
	}
}