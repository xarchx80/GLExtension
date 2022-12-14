#pragma once

#pragma comment(lib, "Opengl32")

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

#include <GL/wglext.h>
#include <GL/glcorearb.h>
#include <GL/glext.h>
#include <GL/GL.h>
#include <assert.h>

#define GL_DECL_PFN(type, func) \
do{ \
	func = reinterpret_cast<type>(wglGetProcAddress(#func));\
	if(!func){ \
		assert(0 && "failed to load func pointer"); \
	}\
}while(false)	// run once

//====================== WGL =============================
extern PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;

//===================== GL EXT ===========================
extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLBUFFERSUBDATAPROC glBufferSubData;

extern PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray;
extern PFNGLVERTEXATTRIBPOINTERPROC		glVertexAttribPointer;
extern PFNGLBINDVERTEXARRAYPROC			glBindVertexArray;
extern PFNGLGENVERTEXARRAYSPROC			glGenVertexArrays;
extern PFNGLCREATEVERTEXARRAYSPROC		glCreateVertexArrays;
extern PFNGLVERTEXATTRIBDIVISORPROC		glVertexAttribDivisor;
extern PFNGLDRAWARRAYSINSTANCEDPROC		glDrawArraysInstanced;
extern PFNGLDRAWELEMENTSBASEVERTEXPROC  glDrawElementsBaseVertex;

extern PFNGLDELETEBUFFERSPROC			glDeleteBuffers;
extern PFNGLDELETEVERTEXARRAYSPROC		glDeleteVertexArrays;

//===================== PROGRAM ==========================
extern PFNGLCREATEPROGRAMPROC			glCreateProgram;
extern PFNGLATTACHSHADERPROC			glAttachShader;
extern PFNGLLINKPROGRAMPROC				glLinkProgram;
extern PFNGLGETPROGRAMIVPROC			glGetProgramiv;
extern PFNGLDELETESHADERPROC			glDeleteShader;
extern PFNGLDELETEPROGRAMPROC			glDeleteProgram;
extern PFNGLUSEPROGRAMPROC				glUseProgram;
extern PFNGLCREATESHADERPROC			glCreateShader;
extern PFNGLSHADERSOURCEPROC			glShaderSource;
extern PFNGLCOMPILESHADERPROC			glCompileShader;
extern PFNGLGETSHADERIVPROC				glGetShaderiv;
extern PFNGLGETPROGRAMINFOLOGPROC		glGetProgramInfoLog;
extern PFNGLGETSHADERINFOLOGPROC		glGetShaderInfoLog;

//=================== TEXTURE ===========================

extern PFNGLACTIVETEXTUREPROC			glActiveTexture;
extern PFNGLCREATETEXTURESPROC			glCreateTextures;
extern PFNGLTEXTUREPARAMETERIPROC		glTextureParameteri;
extern PFNGLBINDTEXTUREUNITPROC			glBindTextureUnit;
extern PFNGLGENERATEMIPMAPPROC			glGenerateMipmap;

//=================== FRAME BUFFER ======================
extern PFNGLGENFRAMEBUFFERSPROC			glGenFramebuffers;
extern PFNGLBINDFRAMEBUFFERPROC			glBindFramebuffer;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC	glFramebufferTexture2D;
extern PFNGLDRAWBUFFERSPROC				glDrawBuffers;
extern PFNGLGENRENDERBUFFERSPROC		glGenRenderbuffers;
extern PFNGLBINDRENDERBUFFERPROC		glBindRenderbuffer;
extern PFNGLRENDERBUFFERSTORAGEPROC		glRenderbufferStorage;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC	glCheckFramebufferStatus;
extern PFNGLBLITFRAMEBUFFERPROC			glBlitFramebuffer;

//=================== EXT ===============================
extern PFNGLNAMEDBUFFERSUBDATAEXTPROC				glNamedBufferSubDataEXT;
extern PFNGLBINDBUFFERBASEPROC						glBindBufferBase;
extern PFNGLCOMPRESSEDTEXIMAGE2DARBPROC				glCompressedTexImage2DARB;
extern PFNGLBINDBUFFERRANGEPROC						glBindBufferRange;
extern PFNGLDRAWELEMENTSINSTANCEDPROC				glDrawElementsInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC		glDrawElementsInstancedBaseVertex;
extern PFNGLDRAWELEMENTSBASEVERTEXPROC				glDrawElementsBaseVertex;


//================== GL 4.4 ==============================

extern PFNGLCLIPCONTROLPROC				glClipControl;

namespace GL {
	namespace {
		extern bool bLoadedGL = false;
	}
	bool InitGLExtension();
	bool RegistGLFunctions();
}