/*******************************************************************************
 *                                                                              *
 * Author    :  Ari Þór H. Arnbjörnsson                                         *
 * Date      :  22 May 2011                                                     *
 * Website   :  http://flassari.is                                              *
 *                                                                              *
 * License:                                                                     *
 * Use, modification & distribution is subject to Boost Software License Ver 1. *
 * http://www.boost.org/LICENSE_1_0.txt                                         *
 *                                                                              *
 *******************************************************************************/

#include "JNITriangulate.h"
#include "triangulate.h"
#include "triangulate.cpp"

#ifdef ANDROID
#include <android/log.h>
#endif

JNIEXPORT jintArray JNICALL Java_fr_myrddin_triangulate_Triangulate_jniTriangulate (JNIEnv *env, jobject obj, jintArray polygonArray)
{

	jint polygonCount; 
	polygonCount = env->GetArrayLength(polygonArray);
	
	Polygon polygon(polygonCount / 2);
	Polygon solution;

	jint buffer[polygonCount];
	jint i;
	env->GetIntArrayRegion(polygonArray, 0, polygonCount, buffer);
	for (i = 0; i < polygonCount; i += 2) 
	{
		polygon[i / 2] = Vector2d(buffer[i], buffer[i + 1]);
	}

	Triangulate::Process(polygon,solution);
	
	jint count = (int) solution.size();

	if (count > 0)
	{
		jintArray result;
		result = env->NewIntArray( count * 2);

		if (result == NULL) {
			return NULL;
		}

		jint fill[count * 2];
		for (int i = 0; i < count; i++) {
			// Push all the vertices into the array
			fill[i * 2] = solution[i].GetX();
			fill[i * 2 + 1] = solution[i].GetY();
		}
		// Insert the array into the returnArray
		env->SetIntArrayRegion(result, 0, count * 2,fill);
		
		return result;
	}
	return NULL;
}
