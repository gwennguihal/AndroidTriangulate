package fr.myrddin.triangulate;

public class Triangulate
{
	static
	{
		System.loadLibrary("Triangulate");
	}
	
	public int[] triangulate(int[] polygon)
	{
		return jniTriangulate(polygon);
	}
	
	private native int[] jniTriangulate(int[] polygon);
}
