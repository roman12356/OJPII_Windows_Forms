#ifndef OPENGLWATER_H
#define OPENGLWATER_H

#include <windows.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <math.h>
#define M_PI 3.14159265359
#include <iostream>


using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

namespace OpenGLWater
{

	enum _E_STATE
	{
		E_SLOW_MOTION_TRUE,
		E_SLOW_MOTION_FALSE,
		E_TOTAL
	};


	public ref class _COpenGLWater : public System::Windows::Forms::NativeWindow
	{

	private:
		System::Windows::Forms::Form ^ parentForm;
		HDC m_hDC;
		HGLRC m_hglrc;

		int WaterHeight;
		int WaterPositionAmount;
		int FPS = 30;
		int tempint = 0;
		int xrel;
		int AmountOfRange;
		int i;
		GLfloat KRscale;
		double ChairHeight;
		double angle2;
		bool scaleflag;
		bool start;
		_E_STATE SlowMotion;

		List<double>^ WaterPositionY = gcnew List<double>();
		List<double>^ WaterPositionX = gcnew List<double>();


	private:
		double WaterVelocity(int h)
		{

			return (sqrt(2 * 9.80665 * (h)* 0.01));
		}

		double ThrowX(double t, double velocity, double angle)
		{
			return velocity * t * cos(angle);
		}

		double ThrowY(double t, double velocity, double angle)
		{
			return velocity * t * sin(angle) - ((9.80665 * pow(t, 2.)) / 2.);
		}


	public:
		_COpenGLWater(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight) : parentForm(parentForm)
		{
			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if (m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}

		}

		GLvoid RefreshContexts(GLsizei iWidth, GLsizei iHeight)
		{
			//=====
			m_hDC = GetDC((HWND)parentForm->Handle.ToPointer());
			if (m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}

		}


		System::Void Render(System::Void)
		{

			//start = true; 
			glClearColor(153.0f / 255.0f,
				217.0f / 255.0f,
				234.0f / 255.0f,
				1.0f);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();


			//floor
			glColor4f(185.0f / 255.0f,
				122.0f / 255.0f,
				87.0f / 255.0f,
				1.0f);

			glBegin(GL_QUADS);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, 200.0);
			glVertex2f(800.0, 200.0);
			glVertex2f(800.0f, 0.0f);
			glEnd();
			//end floor


			//additional buttons and info for events of animation

			glEnable(GL_TEXTURE_2D);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);




			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);
			//end of additional buttons for events of animation


			if (start == true)
			{
				if (tempint < WaterPositionY->Count-1)
				{
					if (SlowMotion == E_SLOW_MOTION_TRUE)
					{
						tempint++;
					}
					else
					{
						tempint += 5;
					}
				}

				if (tempint > WaterPositionY->Count-1)
				{
					tempint = WaterPositionY->Count - 1;
				}
			}

			if (WaterPositionX[tempint] > 3.5 && tempint < WaterPositionX->Count)
			{
				glTranslatef(350 - WaterPositionX[tempint] * 100, 0.0, 0.0);
			}







			glEnable(GL_POINT_SMOOTH);
			glEnable(GL_LINE_SMOOTH);
			glEnable(GL_MULTISAMPLE);


			//chair
			glLineWidth(10 * KRscale);
			glBegin(GL_LINES);

			//brown dark
			glColor4f(98.0f / 255.0f,
				83.0f / 255.0f,
				60.0f / 255.0f,
				1.0f);

			glVertex2f(120.0f, 100.0f);
			glVertex2f(120.0f, 290.0f);

			glVertex2f(190.0f, 100.0f);
			glVertex2f(190.0f, 290.0f);

			glVertex2f(120.0f, 286.0f);
			glVertex2f(190.0f, 286.0f);

			glEnd();
			//end chair


			//vessel
			glLineWidth(2 * KRscale);

			//dark purple - blue
			glColor4f(131.0f / 255.0f,
				153.0f / 255.0f,
				205.0f / 255.0f,
				1.0f);

			glBegin(GL_LINES);
			glVertex2f(110.0f, 300.0f);
			glVertex2f(110.0f, 325.0f + (float)WaterHeight);

			glVertex2f(200.0f, 300.0f);
			glVertex2f(200.0f, 325.0f + (float)WaterHeight);

			glVertex2f(120.0f, 290.0f);
			glVertex2f(190.0f, 290.0f);


			glEnd();


			//left and right circulated sides of vessel
			glBegin(GL_LINE_STRIP);
			for (angle2 = 0; angle2 < M_PI / 2;
				glVertex2f(120.0f - cos(angle2) * 10, 300.0f - sin(angle2) * 10),
				angle2 += 0.1);
			glEnd();

			glBegin(GL_LINE_STRIP);
			for (angle2 = 0; angle2 < M_PI / 2;
				glVertex2f(190.0f + sin(angle2) * 10, 300.0f - cos(angle2) * 10),
				angle2 += 0.1);
			glEnd();
			//end vessel


			//Water
			glColor4f(43.0f / 255.0f,
				75.0f / 255.0f,
				230.0f / 255.0f,
				1.0f);

			//fill the vessel
			glBegin(GL_POLYGON);
			for (angle2 = 0; angle2 < M_PI * 2;
				glVertex2f(189.0f + sin(angle2) * 10, 301.0f - cos(angle2) * 10),
				angle2 += 0.1);
			glEnd();

			glBegin(GL_POLYGON);
			for (angle2 = 0; angle2 < M_PI * 2;
				glVertex2f(121.0f + sin(angle2) * 10, 301.0f - cos(angle2) * 10),
				angle2 += 0.1);
			glEnd();


			glLineWidth(10 * KRscale);

			glBegin(GL_LINES);

			glVertex2f(118.0f, 294.0f);
			glVertex2f(189.0f, 294.0f);

			glVertex2f(118.0f, 299.0f);
			glVertex2f(189.0f, 299.0f);

			glVertex2f(111.0f, 304.0f);
			glVertex2f(199.0f, 304.0f);

			for (int i = 0; i < WaterHeight; i += 5)
			{
				glVertex2f(111.0f, 309.0f + (float)i);
				glVertex2f(199.0f, 309.0f + (float)i);
			}

			glEnd();
			//end filing the vessel

			


			glLineWidth(2 * KRscale);

			glBegin(GL_LINES);

			glVertex2f(195.0f, 300.0f);
			glVertex2f(200.0f, 300.0f);


			//Water stream

			for (int i = 0; i <= tempint - 2;
				glVertex2f(200.0f + WaterPositionX[i] * 100, 300.0f + WaterPositionY[i] * 100),
				glVertex2f(200.0f + WaterPositionX[i + 1] * 100, 300.0f + WaterPositionY[i + 1] * 100),
				i++);

			glEnd();



			glDisable(GL_BLEND);


			glBegin(GL_LINES);

			//black
			glColor4f(0.0f,
				0.0f,
				0.0f,
				1.0f);

			glVertex2f(200.0f, 100.0f);
			glVertex2f(300.0f + WaterPositionX[WaterPositionX->Count - 1] * 100 + 100, 100.0f);

			for (int i = 0; i < WaterPositionX[WaterPositionX->Count -1] * 100 + 100; i += 100)
			{
				glVertex2f(200.0f + (float)i, 100.0f);
				glVertex2f(200.0f + (float)i, 90.0f);

			}

			glEnd();


		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		System::Void Reset()
		{
			xrel = 0;
			KRscale = 1.0f;
			SlowMotion = E_SLOW_MOTION_FALSE;;
			scaleflag = false;
			start = false;
			tempint = 0;
		}

		System::Void Count(int Height)
		{
			WaterPositionAmount = 0;
			WaterHeight = Height;

			WaterPositionX->Clear();
			WaterPositionY->Clear();

			ChairHeight = 2.0;

			do
			{
				WaterPositionY->Add(ThrowY((double)WaterPositionAmount / (FPS * 5), WaterVelocity(WaterHeight), 0));
				WaterPositionX->Add(ThrowX((double)WaterPositionAmount / (FPS * 5), WaterVelocity(WaterHeight), 0));
				WaterPositionAmount++;

			} while (WaterPositionY[WaterPositionY->Count - 1] >= -ChairHeight);


			Reset();
		}

		double GetRangeMax()
		{
			return WaterPositionX[WaterPositionY->Count - 1];
		}

		double GetPosX()
		{
			return WaterPositionX[tempint];
		}

		double GetPosY()
		{
			return WaterPositionY[WaterPositionY->Count - 1 - tempint];
		}

		System::Void Start()
		{
			start = (start == true ? false : true);
			if (tempint == WaterPositionAmount - 1)
			{
				Reset();
			}
		}

		System::Void ChangeSlowMo()
		{
			SlowMotion = (SlowMotion == E_SLOW_MOTION_FALSE ? E_SLOW_MOTION_TRUE : E_SLOW_MOTION_FALSE);
		}

		System::Boolean GetSlowMo()
		{
			return (SlowMotion == E_SLOW_MOTION_TRUE ? true : false);
		}

		System::Double GetTime()
		{
			return (double)tempint / (FPS * 5.);
		}


		~_COpenGLWater(System::Void)
		{
			System::Console::WriteLine("Destructor _COpenGLWater");
			this->DestroyHandle();
		}

	protected:

		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
				1,											// Version Number
				PFD_DRAW_TO_WINDOW |						// Format Must Support Window
				PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
				PFD_DOUBLEBUFFER,							// Must Support Double Buffering
				PFD_TYPE_RGBA,								// Request An RGBA Format
				16,										// Select Our Color Depth
				0, 0, 0, 0, 0, 0,							// Color Bits Ignored
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				16,											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// Main Drawing Layer
				0,											// Reserved
				0, 0, 0										// Layer Masks Ignored
			};

			GLint  iPixelFormat;

			// get the device context's best, available pixel format match 
			if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}


		bool InitGL(GLvoid)										// All setup for opengl goes here
		{

			//Initialize GLEW
			glewExperimental = GL_TRUE;
			GLenum glewError = glewInit();
			if (glewError != GLEW_OK)
			{
				System::Console::Write("Error initializing GLEW! %s\n");
				System::Console::WriteLine(glewGetErrorString(glewError));
			}

			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
			return TRUE;										// Initialisation went ok


		}


		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height <= 0)										// Prevent A Divide By Zero By
			{
				height = 1;										// Making Height Equal One
			}

			glViewport(0, 0, width, height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			// Calculate The Aspect Ratio Of The Window
			//gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
			glOrtho(0, width, 0, height, -20.0, 20.0);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}




	};



}


#endif