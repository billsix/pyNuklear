/*

    This file is a modified version of gl3w_gen.py, part of gl3w
    (hosted at https://github.com/skaslev/gl3w)

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or
    distribute this software, either in source code form or as a compiled
    binary, for any purpose, commercial or non-commercial, and by any
    means.

    In jurisdictions that recognize copyright laws, the author or authors
    of this software dedicate any and all copyright interest in the
    software to the public domain. We make this dedication for the benefit
    of the public at large and to the detriment of our heirs and
    successors. We intend this dedication to be an overt act of
    relinquishment in perpetuity of all present and future rights to this
    software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

============================================================================
    You MUST

        #define GL3W_IMPLEMENTATION

    in EXACLY _one_ C or C++ file that includes this header, BEFORE the include,
    like this:

        #define GL3W_IMPLEMENTATION
        #include "gl3w.h"

    All other files should just #include "gl3w.h" without the #define.

*/

#ifndef __gl3w_h_
#define __gl3w_h_

#include "glcorearb.h"

#ifndef __gl_h_
#define __gl_h_
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*GL3WglProc)(void);

/* gl3w api */
int gl3w_init(void);
int gl3w_is_supported(int major, int minor);
GL3WglProc gl3w_get_proc_address(char const *proc);

/* OpenGL functions */
extern PFNGLACTIVEPROGRAMEXTPROC                            gl3wActiveProgramEXT;
extern PFNGLACTIVESHADERPROGRAMPROC                         gl3wActiveShaderProgram;
extern PFNGLACTIVETEXTUREPROC                               gl3wActiveTexture;
extern PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC         gl3wApplyFramebufferAttachmentCMAAINTEL;
extern PFNGLATTACHSHADERPROC                                gl3wAttachShader;
extern PFNGLBEGINCONDITIONALRENDERPROC                      gl3wBeginConditionalRender;
extern PFNGLBEGINCONDITIONALRENDERNVPROC                    gl3wBeginConditionalRenderNV;
extern PFNGLBEGINPERFMONITORAMDPROC                         gl3wBeginPerfMonitorAMD;
extern PFNGLBEGINPERFQUERYINTELPROC                         gl3wBeginPerfQueryINTEL;
extern PFNGLBEGINQUERYPROC                                  gl3wBeginQuery;
extern PFNGLBEGINQUERYINDEXEDPROC                           gl3wBeginQueryIndexed;
extern PFNGLBEGINTRANSFORMFEEDBACKPROC                      gl3wBeginTransformFeedback;
extern PFNGLBINDATTRIBLOCATIONPROC                          gl3wBindAttribLocation;
extern PFNGLBINDBUFFERPROC                                  gl3wBindBuffer;
extern PFNGLBINDBUFFERBASEPROC                              gl3wBindBufferBase;
extern PFNGLBINDBUFFERRANGEPROC                             gl3wBindBufferRange;
extern PFNGLBINDBUFFERSBASEPROC                             gl3wBindBuffersBase;
extern PFNGLBINDBUFFERSRANGEPROC                            gl3wBindBuffersRange;
extern PFNGLBINDFRAGDATALOCATIONPROC                        gl3wBindFragDataLocation;
extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC                 gl3wBindFragDataLocationIndexed;
extern PFNGLBINDFRAMEBUFFERPROC                             gl3wBindFramebuffer;
extern PFNGLBINDIMAGETEXTUREPROC                            gl3wBindImageTexture;
extern PFNGLBINDIMAGETEXTURESPROC                           gl3wBindImageTextures;
extern PFNGLBINDMULTITEXTUREEXTPROC                         gl3wBindMultiTextureEXT;
extern PFNGLBINDPROGRAMPIPELINEPROC                         gl3wBindProgramPipeline;
extern PFNGLBINDRENDERBUFFERPROC                            gl3wBindRenderbuffer;
extern PFNGLBINDSAMPLERPROC                                 gl3wBindSampler;
extern PFNGLBINDSAMPLERSPROC                                gl3wBindSamplers;
extern PFNGLBINDTEXTUREPROC                                 gl3wBindTexture;
extern PFNGLBINDTEXTUREUNITPROC                             gl3wBindTextureUnit;
extern PFNGLBINDTEXTURESPROC                                gl3wBindTextures;
extern PFNGLBINDTRANSFORMFEEDBACKPROC                       gl3wBindTransformFeedback;
extern PFNGLBINDVERTEXARRAYPROC                             gl3wBindVertexArray;
extern PFNGLBINDVERTEXBUFFERPROC                            gl3wBindVertexBuffer;
extern PFNGLBINDVERTEXBUFFERSPROC                           gl3wBindVertexBuffers;
extern PFNGLBLENDBARRIERKHRPROC                             gl3wBlendBarrierKHR;
extern PFNGLBLENDBARRIERNVPROC                              gl3wBlendBarrierNV;
extern PFNGLBLENDCOLORPROC                                  gl3wBlendColor;
extern PFNGLBLENDEQUATIONPROC                               gl3wBlendEquation;
extern PFNGLBLENDEQUATIONSEPARATEPROC                       gl3wBlendEquationSeparate;
extern PFNGLBLENDEQUATIONSEPARATEIPROC                      gl3wBlendEquationSeparatei;
extern PFNGLBLENDEQUATIONSEPARATEIARBPROC                   gl3wBlendEquationSeparateiARB;
extern PFNGLBLENDEQUATIONIPROC                              gl3wBlendEquationi;
extern PFNGLBLENDEQUATIONIARBPROC                           gl3wBlendEquationiARB;
extern PFNGLBLENDFUNCPROC                                   gl3wBlendFunc;
extern PFNGLBLENDFUNCSEPARATEPROC                           gl3wBlendFuncSeparate;
extern PFNGLBLENDFUNCSEPARATEIPROC                          gl3wBlendFuncSeparatei;
extern PFNGLBLENDFUNCSEPARATEIARBPROC                       gl3wBlendFuncSeparateiARB;
extern PFNGLBLENDFUNCIPROC                                  gl3wBlendFunci;
extern PFNGLBLENDFUNCIARBPROC                               gl3wBlendFunciARB;
extern PFNGLBLENDPARAMETERINVPROC                           gl3wBlendParameteriNV;
extern PFNGLBLITFRAMEBUFFERPROC                             gl3wBlitFramebuffer;
extern PFNGLBLITNAMEDFRAMEBUFFERPROC                        gl3wBlitNamedFramebuffer;
extern PFNGLBUFFERADDRESSRANGENVPROC                        gl3wBufferAddressRangeNV;
extern PFNGLBUFFERDATAPROC                                  gl3wBufferData;
extern PFNGLBUFFERPAGECOMMITMENTARBPROC                     gl3wBufferPageCommitmentARB;
extern PFNGLBUFFERSTORAGEPROC                               gl3wBufferStorage;
extern PFNGLBUFFERSUBDATAPROC                               gl3wBufferSubData;
extern PFNGLCALLCOMMANDLISTNVPROC                           gl3wCallCommandListNV;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC                      gl3wCheckFramebufferStatus;
extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC                 gl3wCheckNamedFramebufferStatus;
extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC              gl3wCheckNamedFramebufferStatusEXT;
extern PFNGLCLAMPCOLORPROC                                  gl3wClampColor;
extern PFNGLCLEARPROC                                       gl3wClear;
extern PFNGLCLEARBUFFERDATAPROC                             gl3wClearBufferData;
extern PFNGLCLEARBUFFERSUBDATAPROC                          gl3wClearBufferSubData;
extern PFNGLCLEARBUFFERFIPROC                               gl3wClearBufferfi;
extern PFNGLCLEARBUFFERFVPROC                               gl3wClearBufferfv;
extern PFNGLCLEARBUFFERIVPROC                               gl3wClearBufferiv;
extern PFNGLCLEARBUFFERUIVPROC                              gl3wClearBufferuiv;
extern PFNGLCLEARCOLORPROC                                  gl3wClearColor;
extern PFNGLCLEARDEPTHPROC                                  gl3wClearDepth;
extern PFNGLCLEARDEPTHFPROC                                 gl3wClearDepthf;
extern PFNGLCLEARNAMEDBUFFERDATAPROC                        gl3wClearNamedBufferData;
extern PFNGLCLEARNAMEDBUFFERDATAEXTPROC                     gl3wClearNamedBufferDataEXT;
extern PFNGLCLEARNAMEDBUFFERSUBDATAPROC                     gl3wClearNamedBufferSubData;
extern PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC                  gl3wClearNamedBufferSubDataEXT;
extern PFNGLCLEARNAMEDFRAMEBUFFERFIPROC                     gl3wClearNamedFramebufferfi;
extern PFNGLCLEARNAMEDFRAMEBUFFERFVPROC                     gl3wClearNamedFramebufferfv;
extern PFNGLCLEARNAMEDFRAMEBUFFERIVPROC                     gl3wClearNamedFramebufferiv;
extern PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC                    gl3wClearNamedFramebufferuiv;
extern PFNGLCLEARSTENCILPROC                                gl3wClearStencil;
extern PFNGLCLEARTEXIMAGEPROC                               gl3wClearTexImage;
extern PFNGLCLEARTEXSUBIMAGEPROC                            gl3wClearTexSubImage;
extern PFNGLCLIENTATTRIBDEFAULTEXTPROC                      gl3wClientAttribDefaultEXT;
extern PFNGLCLIENTWAITSYNCPROC                              gl3wClientWaitSync;
extern PFNGLCLIPCONTROLPROC                                 gl3wClipControl;
extern PFNGLCOLORFORMATNVPROC                               gl3wColorFormatNV;
extern PFNGLCOLORMASKPROC                                   gl3wColorMask;
extern PFNGLCOLORMASKIPROC                                  gl3wColorMaski;
extern PFNGLCOMMANDLISTSEGMENTSNVPROC                       gl3wCommandListSegmentsNV;
extern PFNGLCOMPILECOMMANDLISTNVPROC                        gl3wCompileCommandListNV;
extern PFNGLCOMPILESHADERPROC                               gl3wCompileShader;
extern PFNGLCOMPILESHADERINCLUDEARBPROC                     gl3wCompileShaderIncludeARB;
extern PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC                gl3wCompressedMultiTexImage1DEXT;
extern PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC                gl3wCompressedMultiTexImage2DEXT;
extern PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC                gl3wCompressedMultiTexImage3DEXT;
extern PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC             gl3wCompressedMultiTexSubImage1DEXT;
extern PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC             gl3wCompressedMultiTexSubImage2DEXT;
extern PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC             gl3wCompressedMultiTexSubImage3DEXT;
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC                        gl3wCompressedTexImage1D;
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC                        gl3wCompressedTexImage2D;
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC                        gl3wCompressedTexImage3D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC                     gl3wCompressedTexSubImage1D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC                     gl3wCompressedTexSubImage2D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC                     gl3wCompressedTexSubImage3D;
extern PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC                 gl3wCompressedTextureImage1DEXT;
extern PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC                 gl3wCompressedTextureImage2DEXT;
extern PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC                 gl3wCompressedTextureImage3DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC                 gl3wCompressedTextureSubImage1D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC              gl3wCompressedTextureSubImage1DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC                 gl3wCompressedTextureSubImage2D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC              gl3wCompressedTextureSubImage2DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC                 gl3wCompressedTextureSubImage3D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC              gl3wCompressedTextureSubImage3DEXT;
extern PFNGLCONSERVATIVERASTERPARAMETERFNVPROC              gl3wConservativeRasterParameterfNV;
extern PFNGLCONSERVATIVERASTERPARAMETERINVPROC              gl3wConservativeRasterParameteriNV;
extern PFNGLCOPYBUFFERSUBDATAPROC                           gl3wCopyBufferSubData;
extern PFNGLCOPYIMAGESUBDATAPROC                            gl3wCopyImageSubData;
extern PFNGLCOPYMULTITEXIMAGE1DEXTPROC                      gl3wCopyMultiTexImage1DEXT;
extern PFNGLCOPYMULTITEXIMAGE2DEXTPROC                      gl3wCopyMultiTexImage2DEXT;
extern PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC                   gl3wCopyMultiTexSubImage1DEXT;
extern PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC                   gl3wCopyMultiTexSubImage2DEXT;
extern PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC                   gl3wCopyMultiTexSubImage3DEXT;
extern PFNGLCOPYNAMEDBUFFERSUBDATAPROC                      gl3wCopyNamedBufferSubData;
extern PFNGLCOPYPATHNVPROC                                  gl3wCopyPathNV;
extern PFNGLCOPYTEXIMAGE1DPROC                              gl3wCopyTexImage1D;
extern PFNGLCOPYTEXIMAGE2DPROC                              gl3wCopyTexImage2D;
extern PFNGLCOPYTEXSUBIMAGE1DPROC                           gl3wCopyTexSubImage1D;
extern PFNGLCOPYTEXSUBIMAGE2DPROC                           gl3wCopyTexSubImage2D;
extern PFNGLCOPYTEXSUBIMAGE3DPROC                           gl3wCopyTexSubImage3D;
extern PFNGLCOPYTEXTUREIMAGE1DEXTPROC                       gl3wCopyTextureImage1DEXT;
extern PFNGLCOPYTEXTUREIMAGE2DEXTPROC                       gl3wCopyTextureImage2DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE1DPROC                       gl3wCopyTextureSubImage1D;
extern PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC                    gl3wCopyTextureSubImage1DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE2DPROC                       gl3wCopyTextureSubImage2D;
extern PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC                    gl3wCopyTextureSubImage2DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE3DPROC                       gl3wCopyTextureSubImage3D;
extern PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC                    gl3wCopyTextureSubImage3DEXT;
extern PFNGLCOVERFILLPATHINSTANCEDNVPROC                    gl3wCoverFillPathInstancedNV;
extern PFNGLCOVERFILLPATHNVPROC                             gl3wCoverFillPathNV;
extern PFNGLCOVERSTROKEPATHINSTANCEDNVPROC                  gl3wCoverStrokePathInstancedNV;
extern PFNGLCOVERSTROKEPATHNVPROC                           gl3wCoverStrokePathNV;
extern PFNGLCOVERAGEMODULATIONNVPROC                        gl3wCoverageModulationNV;
extern PFNGLCOVERAGEMODULATIONTABLENVPROC                   gl3wCoverageModulationTableNV;
extern PFNGLCREATEBUFFERSPROC                               gl3wCreateBuffers;
extern PFNGLCREATECOMMANDLISTSNVPROC                        gl3wCreateCommandListsNV;
extern PFNGLCREATEFRAMEBUFFERSPROC                          gl3wCreateFramebuffers;
extern PFNGLCREATEPERFQUERYINTELPROC                        gl3wCreatePerfQueryINTEL;
extern PFNGLCREATEPROGRAMPROC                               gl3wCreateProgram;
extern PFNGLCREATEPROGRAMPIPELINESPROC                      gl3wCreateProgramPipelines;
extern PFNGLCREATEQUERIESPROC                               gl3wCreateQueries;
extern PFNGLCREATERENDERBUFFERSPROC                         gl3wCreateRenderbuffers;
extern PFNGLCREATESAMPLERSPROC                              gl3wCreateSamplers;
extern PFNGLCREATESHADERPROC                                gl3wCreateShader;
extern PFNGLCREATESHADERPROGRAMEXTPROC                      gl3wCreateShaderProgramEXT;
extern PFNGLCREATESHADERPROGRAMVPROC                        gl3wCreateShaderProgramv;
extern PFNGLCREATESTATESNVPROC                              gl3wCreateStatesNV;
extern PFNGLCREATESYNCFROMCLEVENTARBPROC                    gl3wCreateSyncFromCLeventARB;
extern PFNGLCREATETEXTURESPROC                              gl3wCreateTextures;
extern PFNGLCREATETRANSFORMFEEDBACKSPROC                    gl3wCreateTransformFeedbacks;
extern PFNGLCREATEVERTEXARRAYSPROC                          gl3wCreateVertexArrays;
extern PFNGLCULLFACEPROC                                    gl3wCullFace;
extern PFNGLDEBUGMESSAGECALLBACKPROC                        gl3wDebugMessageCallback;
extern PFNGLDEBUGMESSAGECALLBACKARBPROC                     gl3wDebugMessageCallbackARB;
extern PFNGLDEBUGMESSAGECONTROLPROC                         gl3wDebugMessageControl;
extern PFNGLDEBUGMESSAGECONTROLARBPROC                      gl3wDebugMessageControlARB;
extern PFNGLDEBUGMESSAGEINSERTPROC                          gl3wDebugMessageInsert;
extern PFNGLDEBUGMESSAGEINSERTARBPROC                       gl3wDebugMessageInsertARB;
extern PFNGLDELETEBUFFERSPROC                               gl3wDeleteBuffers;
extern PFNGLDELETECOMMANDLISTSNVPROC                        gl3wDeleteCommandListsNV;
extern PFNGLDELETEFRAMEBUFFERSPROC                          gl3wDeleteFramebuffers;
extern PFNGLDELETENAMEDSTRINGARBPROC                        gl3wDeleteNamedStringARB;
extern PFNGLDELETEPATHSNVPROC                               gl3wDeletePathsNV;
extern PFNGLDELETEPERFMONITORSAMDPROC                       gl3wDeletePerfMonitorsAMD;
extern PFNGLDELETEPERFQUERYINTELPROC                        gl3wDeletePerfQueryINTEL;
extern PFNGLDELETEPROGRAMPROC                               gl3wDeleteProgram;
extern PFNGLDELETEPROGRAMPIPELINESPROC                      gl3wDeleteProgramPipelines;
extern PFNGLDELETEQUERIESPROC                               gl3wDeleteQueries;
extern PFNGLDELETERENDERBUFFERSPROC                         gl3wDeleteRenderbuffers;
extern PFNGLDELETESAMPLERSPROC                              gl3wDeleteSamplers;
extern PFNGLDELETESHADERPROC                                gl3wDeleteShader;
extern PFNGLDELETESTATESNVPROC                              gl3wDeleteStatesNV;
extern PFNGLDELETESYNCPROC                                  gl3wDeleteSync;
extern PFNGLDELETETEXTURESPROC                              gl3wDeleteTextures;
extern PFNGLDELETETRANSFORMFEEDBACKSPROC                    gl3wDeleteTransformFeedbacks;
extern PFNGLDELETEVERTEXARRAYSPROC                          gl3wDeleteVertexArrays;
extern PFNGLDEPTHFUNCPROC                                   gl3wDepthFunc;
extern PFNGLDEPTHMASKPROC                                   gl3wDepthMask;
extern PFNGLDEPTHRANGEPROC                                  gl3wDepthRange;
extern PFNGLDEPTHRANGEARRAYVPROC                            gl3wDepthRangeArrayv;
extern PFNGLDEPTHRANGEINDEXEDPROC                           gl3wDepthRangeIndexed;
extern PFNGLDEPTHRANGEFPROC                                 gl3wDepthRangef;
extern PFNGLDETACHSHADERPROC                                gl3wDetachShader;
extern PFNGLDISABLEPROC                                     gl3wDisable;
extern PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC                gl3wDisableClientStateIndexedEXT;
extern PFNGLDISABLECLIENTSTATEIEXTPROC                      gl3wDisableClientStateiEXT;
extern PFNGLDISABLEINDEXEDEXTPROC                           gl3wDisableIndexedEXT;
extern PFNGLDISABLEVERTEXARRAYATTRIBPROC                    gl3wDisableVertexArrayAttrib;
extern PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC                 gl3wDisableVertexArrayAttribEXT;
extern PFNGLDISABLEVERTEXARRAYEXTPROC                       gl3wDisableVertexArrayEXT;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC                    gl3wDisableVertexAttribArray;
extern PFNGLDISABLEIPROC                                    gl3wDisablei;
extern PFNGLDISPATCHCOMPUTEPROC                             gl3wDispatchCompute;
extern PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC                 gl3wDispatchComputeGroupSizeARB;
extern PFNGLDISPATCHCOMPUTEINDIRECTPROC                     gl3wDispatchComputeIndirect;
extern PFNGLDRAWARRAYSPROC                                  gl3wDrawArrays;
extern PFNGLDRAWARRAYSINDIRECTPROC                          gl3wDrawArraysIndirect;
extern PFNGLDRAWARRAYSINSTANCEDPROC                         gl3wDrawArraysInstanced;
extern PFNGLDRAWARRAYSINSTANCEDARBPROC                      gl3wDrawArraysInstancedARB;
extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC             gl3wDrawArraysInstancedBaseInstance;
extern PFNGLDRAWARRAYSINSTANCEDEXTPROC                      gl3wDrawArraysInstancedEXT;
extern PFNGLDRAWBUFFERPROC                                  gl3wDrawBuffer;
extern PFNGLDRAWBUFFERSPROC                                 gl3wDrawBuffers;
extern PFNGLDRAWCOMMANDSADDRESSNVPROC                       gl3wDrawCommandsAddressNV;
extern PFNGLDRAWCOMMANDSNVPROC                              gl3wDrawCommandsNV;
extern PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC                 gl3wDrawCommandsStatesAddressNV;
extern PFNGLDRAWCOMMANDSSTATESNVPROC                        gl3wDrawCommandsStatesNV;
extern PFNGLDRAWELEMENTSPROC                                gl3wDrawElements;
extern PFNGLDRAWELEMENTSBASEVERTEXPROC                      gl3wDrawElementsBaseVertex;
extern PFNGLDRAWELEMENTSINDIRECTPROC                        gl3wDrawElementsIndirect;
extern PFNGLDRAWELEMENTSINSTANCEDPROC                       gl3wDrawElementsInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDARBPROC                    gl3wDrawElementsInstancedARB;
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC           gl3wDrawElementsInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC             gl3wDrawElementsInstancedBaseVertex;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC gl3wDrawElementsInstancedBaseVertexBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDEXTPROC                    gl3wDrawElementsInstancedEXT;
extern PFNGLDRAWRANGEELEMENTSPROC                           gl3wDrawRangeElements;
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC                 gl3wDrawRangeElementsBaseVertex;
extern PFNGLDRAWTRANSFORMFEEDBACKPROC                       gl3wDrawTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC              gl3wDrawTransformFeedbackInstanced;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC                 gl3wDrawTransformFeedbackStream;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC        gl3wDrawTransformFeedbackStreamInstanced;
extern PFNGLDRAWVKIMAGENVPROC                               gl3wDrawVkImageNV;
extern PFNGLEDGEFLAGFORMATNVPROC                            gl3wEdgeFlagFormatNV;
extern PFNGLENABLEPROC                                      gl3wEnable;
extern PFNGLENABLECLIENTSTATEINDEXEDEXTPROC                 gl3wEnableClientStateIndexedEXT;
extern PFNGLENABLECLIENTSTATEIEXTPROC                       gl3wEnableClientStateiEXT;
extern PFNGLENABLEINDEXEDEXTPROC                            gl3wEnableIndexedEXT;
extern PFNGLENABLEVERTEXARRAYATTRIBPROC                     gl3wEnableVertexArrayAttrib;
extern PFNGLENABLEVERTEXARRAYATTRIBEXTPROC                  gl3wEnableVertexArrayAttribEXT;
extern PFNGLENABLEVERTEXARRAYEXTPROC                        gl3wEnableVertexArrayEXT;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC                     gl3wEnableVertexAttribArray;
extern PFNGLENABLEIPROC                                     gl3wEnablei;
extern PFNGLENDCONDITIONALRENDERPROC                        gl3wEndConditionalRender;
extern PFNGLENDCONDITIONALRENDERNVPROC                      gl3wEndConditionalRenderNV;
extern PFNGLENDPERFMONITORAMDPROC                           gl3wEndPerfMonitorAMD;
extern PFNGLENDPERFQUERYINTELPROC                           gl3wEndPerfQueryINTEL;
extern PFNGLENDQUERYPROC                                    gl3wEndQuery;
extern PFNGLENDQUERYINDEXEDPROC                             gl3wEndQueryIndexed;
extern PFNGLENDTRANSFORMFEEDBACKPROC                        gl3wEndTransformFeedback;
extern PFNGLEVALUATEDEPTHVALUESARBPROC                      gl3wEvaluateDepthValuesARB;
extern PFNGLFENCESYNCPROC                                   gl3wFenceSync;
extern PFNGLFINISHPROC                                      gl3wFinish;
extern PFNGLFLUSHPROC                                       gl3wFlush;
extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC                      gl3wFlushMappedBufferRange;
extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC                 gl3wFlushMappedNamedBufferRange;
extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC              gl3wFlushMappedNamedBufferRangeEXT;
extern PFNGLFOGCOORDFORMATNVPROC                            gl3wFogCoordFormatNV;
extern PFNGLFRAGMENTCOVERAGECOLORNVPROC                     gl3wFragmentCoverageColorNV;
extern PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC                    gl3wFramebufferDrawBufferEXT;
extern PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC                   gl3wFramebufferDrawBuffersEXT;
extern PFNGLFRAMEBUFFERPARAMETERIPROC                       gl3wFramebufferParameteri;
extern PFNGLFRAMEBUFFERREADBUFFEREXTPROC                    gl3wFramebufferReadBufferEXT;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC                     gl3wFramebufferRenderbuffer;
extern PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC             gl3wFramebufferSampleLocationsfvARB;
extern PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC              gl3wFramebufferSampleLocationsfvNV;
extern PFNGLFRAMEBUFFERTEXTUREPROC                          gl3wFramebufferTexture;
extern PFNGLFRAMEBUFFERTEXTURE1DPROC                        gl3wFramebufferTexture1D;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC                        gl3wFramebufferTexture2D;
extern PFNGLFRAMEBUFFERTEXTURE3DPROC                        gl3wFramebufferTexture3D;
extern PFNGLFRAMEBUFFERTEXTUREARBPROC                       gl3wFramebufferTextureARB;
extern PFNGLFRAMEBUFFERTEXTUREFACEARBPROC                   gl3wFramebufferTextureFaceARB;
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC                     gl3wFramebufferTextureLayer;
extern PFNGLFRAMEBUFFERTEXTURELAYERARBPROC                  gl3wFramebufferTextureLayerARB;
extern PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC              gl3wFramebufferTextureMultiviewOVR;
extern PFNGLFRONTFACEPROC                                   gl3wFrontFace;
extern PFNGLGENBUFFERSPROC                                  gl3wGenBuffers;
extern PFNGLGENFRAMEBUFFERSPROC                             gl3wGenFramebuffers;
extern PFNGLGENPATHSNVPROC                                  gl3wGenPathsNV;
extern PFNGLGENPERFMONITORSAMDPROC                          gl3wGenPerfMonitorsAMD;
extern PFNGLGENPROGRAMPIPELINESPROC                         gl3wGenProgramPipelines;
extern PFNGLGENQUERIESPROC                                  gl3wGenQueries;
extern PFNGLGENRENDERBUFFERSPROC                            gl3wGenRenderbuffers;
extern PFNGLGENSAMPLERSPROC                                 gl3wGenSamplers;
extern PFNGLGENTEXTURESPROC                                 gl3wGenTextures;
extern PFNGLGENTRANSFORMFEEDBACKSPROC                       gl3wGenTransformFeedbacks;
extern PFNGLGENVERTEXARRAYSPROC                             gl3wGenVertexArrays;
extern PFNGLGENERATEMIPMAPPROC                              gl3wGenerateMipmap;
extern PFNGLGENERATEMULTITEXMIPMAPEXTPROC                   gl3wGenerateMultiTexMipmapEXT;
extern PFNGLGENERATETEXTUREMIPMAPPROC                       gl3wGenerateTextureMipmap;
extern PFNGLGENERATETEXTUREMIPMAPEXTPROC                    gl3wGenerateTextureMipmapEXT;
extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC              gl3wGetActiveAtomicCounterBufferiv;
extern PFNGLGETACTIVEATTRIBPROC                             gl3wGetActiveAttrib;
extern PFNGLGETACTIVESUBROUTINENAMEPROC                     gl3wGetActiveSubroutineName;
extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC              gl3wGetActiveSubroutineUniformName;
extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC                gl3wGetActiveSubroutineUniformiv;
extern PFNGLGETACTIVEUNIFORMPROC                            gl3wGetActiveUniform;
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC                   gl3wGetActiveUniformBlockName;
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC                     gl3wGetActiveUniformBlockiv;
extern PFNGLGETACTIVEUNIFORMNAMEPROC                        gl3wGetActiveUniformName;
extern PFNGLGETACTIVEUNIFORMSIVPROC                         gl3wGetActiveUniformsiv;
extern PFNGLGETATTACHEDSHADERSPROC                          gl3wGetAttachedShaders;
extern PFNGLGETATTRIBLOCATIONPROC                           gl3wGetAttribLocation;
extern PFNGLGETBOOLEANINDEXEDVEXTPROC                       gl3wGetBooleanIndexedvEXT;
extern PFNGLGETBOOLEANI_VPROC                               gl3wGetBooleani_v;
extern PFNGLGETBOOLEANVPROC                                 gl3wGetBooleanv;
extern PFNGLGETBUFFERPARAMETERI64VPROC                      gl3wGetBufferParameteri64v;
extern PFNGLGETBUFFERPARAMETERIVPROC                        gl3wGetBufferParameteriv;
extern PFNGLGETBUFFERPARAMETERUI64VNVPROC                   gl3wGetBufferParameterui64vNV;
extern PFNGLGETBUFFERPOINTERVPROC                           gl3wGetBufferPointerv;
extern PFNGLGETBUFFERSUBDATAPROC                            gl3wGetBufferSubData;
extern PFNGLGETCOMMANDHEADERNVPROC                          gl3wGetCommandHeaderNV;
extern PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC               gl3wGetCompressedMultiTexImageEXT;
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC                       gl3wGetCompressedTexImage;
extern PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC                   gl3wGetCompressedTextureImage;
extern PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC                gl3wGetCompressedTextureImageEXT;
extern PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC                gl3wGetCompressedTextureSubImage;
extern PFNGLGETCOVERAGEMODULATIONTABLENVPROC                gl3wGetCoverageModulationTableNV;
extern PFNGLGETDEBUGMESSAGELOGPROC                          gl3wGetDebugMessageLog;
extern PFNGLGETDEBUGMESSAGELOGARBPROC                       gl3wGetDebugMessageLogARB;
extern PFNGLGETDOUBLEINDEXEDVEXTPROC                        gl3wGetDoubleIndexedvEXT;
extern PFNGLGETDOUBLEI_VPROC                                gl3wGetDoublei_v;
extern PFNGLGETDOUBLEI_VEXTPROC                             gl3wGetDoublei_vEXT;
extern PFNGLGETDOUBLEVPROC                                  gl3wGetDoublev;
extern PFNGLGETERRORPROC                                    gl3wGetError;
extern PFNGLGETFIRSTPERFQUERYIDINTELPROC                    gl3wGetFirstPerfQueryIdINTEL;
extern PFNGLGETFLOATINDEXEDVEXTPROC                         gl3wGetFloatIndexedvEXT;
extern PFNGLGETFLOATI_VPROC                                 gl3wGetFloati_v;
extern PFNGLGETFLOATI_VEXTPROC                              gl3wGetFloati_vEXT;
extern PFNGLGETFLOATVPROC                                   gl3wGetFloatv;
extern PFNGLGETFRAGDATAINDEXPROC                            gl3wGetFragDataIndex;
extern PFNGLGETFRAGDATALOCATIONPROC                         gl3wGetFragDataLocation;
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC         gl3wGetFramebufferAttachmentParameteriv;
extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC                   gl3wGetFramebufferParameteriv;
extern PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC                gl3wGetFramebufferParameterivEXT;
extern PFNGLGETGRAPHICSRESETSTATUSPROC                      gl3wGetGraphicsResetStatus;
extern PFNGLGETGRAPHICSRESETSTATUSARBPROC                   gl3wGetGraphicsResetStatusARB;
extern PFNGLGETIMAGEHANDLEARBPROC                           gl3wGetImageHandleARB;
extern PFNGLGETIMAGEHANDLENVPROC                            gl3wGetImageHandleNV;
extern PFNGLGETINTEGER64I_VPROC                             gl3wGetInteger64i_v;
extern PFNGLGETINTEGER64VPROC                               gl3wGetInteger64v;
extern PFNGLGETINTEGERINDEXEDVEXTPROC                       gl3wGetIntegerIndexedvEXT;
extern PFNGLGETINTEGERI_VPROC                               gl3wGetIntegeri_v;
extern PFNGLGETINTEGERUI64I_VNVPROC                         gl3wGetIntegerui64i_vNV;
extern PFNGLGETINTEGERUI64VNVPROC                           gl3wGetIntegerui64vNV;
extern PFNGLGETINTEGERVPROC                                 gl3wGetIntegerv;
extern PFNGLGETINTERNALFORMATSAMPLEIVNVPROC                 gl3wGetInternalformatSampleivNV;
extern PFNGLGETINTERNALFORMATI64VPROC                       gl3wGetInternalformati64v;
extern PFNGLGETINTERNALFORMATIVPROC                         gl3wGetInternalformativ;
extern PFNGLGETMULTITEXENVFVEXTPROC                         gl3wGetMultiTexEnvfvEXT;
extern PFNGLGETMULTITEXENVIVEXTPROC                         gl3wGetMultiTexEnvivEXT;
extern PFNGLGETMULTITEXGENDVEXTPROC                         gl3wGetMultiTexGendvEXT;
extern PFNGLGETMULTITEXGENFVEXTPROC                         gl3wGetMultiTexGenfvEXT;
extern PFNGLGETMULTITEXGENIVEXTPROC                         gl3wGetMultiTexGenivEXT;
extern PFNGLGETMULTITEXIMAGEEXTPROC                         gl3wGetMultiTexImageEXT;
extern PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC              gl3wGetMultiTexLevelParameterfvEXT;
extern PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC              gl3wGetMultiTexLevelParameterivEXT;
extern PFNGLGETMULTITEXPARAMETERIIVEXTPROC                  gl3wGetMultiTexParameterIivEXT;
extern PFNGLGETMULTITEXPARAMETERIUIVEXTPROC                 gl3wGetMultiTexParameterIuivEXT;
extern PFNGLGETMULTITEXPARAMETERFVEXTPROC                   gl3wGetMultiTexParameterfvEXT;
extern PFNGLGETMULTITEXPARAMETERIVEXTPROC                   gl3wGetMultiTexParameterivEXT;
extern PFNGLGETMULTISAMPLEFVPROC                            gl3wGetMultisamplefv;
extern PFNGLGETNAMEDBUFFERPARAMETERI64VPROC                 gl3wGetNamedBufferParameteri64v;
extern PFNGLGETNAMEDBUFFERPARAMETERIVPROC                   gl3wGetNamedBufferParameteriv;
extern PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC                gl3wGetNamedBufferParameterivEXT;
extern PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC              gl3wGetNamedBufferParameterui64vNV;
extern PFNGLGETNAMEDBUFFERPOINTERVPROC                      gl3wGetNamedBufferPointerv;
extern PFNGLGETNAMEDBUFFERPOINTERVEXTPROC                   gl3wGetNamedBufferPointervEXT;
extern PFNGLGETNAMEDBUFFERSUBDATAPROC                       gl3wGetNamedBufferSubData;
extern PFNGLGETNAMEDBUFFERSUBDATAEXTPROC                    gl3wGetNamedBufferSubDataEXT;
extern PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC    gl3wGetNamedFramebufferAttachmentParameteriv;
extern PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC gl3wGetNamedFramebufferAttachmentParameterivEXT;
extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC              gl3wGetNamedFramebufferParameteriv;
extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC           gl3wGetNamedFramebufferParameterivEXT;
extern PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC         gl3wGetNamedProgramLocalParameterIivEXT;
extern PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC        gl3wGetNamedProgramLocalParameterIuivEXT;
extern PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC          gl3wGetNamedProgramLocalParameterdvEXT;
extern PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC          gl3wGetNamedProgramLocalParameterfvEXT;
extern PFNGLGETNAMEDPROGRAMSTRINGEXTPROC                    gl3wGetNamedProgramStringEXT;
extern PFNGLGETNAMEDPROGRAMIVEXTPROC                        gl3wGetNamedProgramivEXT;
extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC             gl3wGetNamedRenderbufferParameteriv;
extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC          gl3wGetNamedRenderbufferParameterivEXT;
extern PFNGLGETNAMEDSTRINGARBPROC                           gl3wGetNamedStringARB;
extern PFNGLGETNAMEDSTRINGIVARBPROC                         gl3wGetNamedStringivARB;
extern PFNGLGETNEXTPERFQUERYIDINTELPROC                     gl3wGetNextPerfQueryIdINTEL;
extern PFNGLGETOBJECTLABELPROC                              gl3wGetObjectLabel;
extern PFNGLGETOBJECTLABELEXTPROC                           gl3wGetObjectLabelEXT;
extern PFNGLGETOBJECTPTRLABELPROC                           gl3wGetObjectPtrLabel;
extern PFNGLGETPATHCOMMANDSNVPROC                           gl3wGetPathCommandsNV;
extern PFNGLGETPATHCOORDSNVPROC                             gl3wGetPathCoordsNV;
extern PFNGLGETPATHDASHARRAYNVPROC                          gl3wGetPathDashArrayNV;
extern PFNGLGETPATHLENGTHNVPROC                             gl3wGetPathLengthNV;
extern PFNGLGETPATHMETRICRANGENVPROC                        gl3wGetPathMetricRangeNV;
extern PFNGLGETPATHMETRICSNVPROC                            gl3wGetPathMetricsNV;
extern PFNGLGETPATHPARAMETERFVNVPROC                        gl3wGetPathParameterfvNV;
extern PFNGLGETPATHPARAMETERIVNVPROC                        gl3wGetPathParameterivNV;
extern PFNGLGETPATHSPACINGNVPROC                            gl3wGetPathSpacingNV;
extern PFNGLGETPERFCOUNTERINFOINTELPROC                     gl3wGetPerfCounterInfoINTEL;
extern PFNGLGETPERFMONITORCOUNTERDATAAMDPROC                gl3wGetPerfMonitorCounterDataAMD;
extern PFNGLGETPERFMONITORCOUNTERINFOAMDPROC                gl3wGetPerfMonitorCounterInfoAMD;
extern PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC              gl3wGetPerfMonitorCounterStringAMD;
extern PFNGLGETPERFMONITORCOUNTERSAMDPROC                   gl3wGetPerfMonitorCountersAMD;
extern PFNGLGETPERFMONITORGROUPSTRINGAMDPROC                gl3wGetPerfMonitorGroupStringAMD;
extern PFNGLGETPERFMONITORGROUPSAMDPROC                     gl3wGetPerfMonitorGroupsAMD;
extern PFNGLGETPERFQUERYDATAINTELPROC                       gl3wGetPerfQueryDataINTEL;
extern PFNGLGETPERFQUERYIDBYNAMEINTELPROC                   gl3wGetPerfQueryIdByNameINTEL;
extern PFNGLGETPERFQUERYINFOINTELPROC                       gl3wGetPerfQueryInfoINTEL;
extern PFNGLGETPOINTERINDEXEDVEXTPROC                       gl3wGetPointerIndexedvEXT;
extern PFNGLGETPOINTERI_VEXTPROC                            gl3wGetPointeri_vEXT;
extern PFNGLGETPOINTERVPROC                                 gl3wGetPointerv;
extern PFNGLGETPROGRAMBINARYPROC                            gl3wGetProgramBinary;
extern PFNGLGETPROGRAMINFOLOGPROC                           gl3wGetProgramInfoLog;
extern PFNGLGETPROGRAMINTERFACEIVPROC                       gl3wGetProgramInterfaceiv;
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC                   gl3wGetProgramPipelineInfoLog;
extern PFNGLGETPROGRAMPIPELINEIVPROC                        gl3wGetProgramPipelineiv;
extern PFNGLGETPROGRAMRESOURCEINDEXPROC                     gl3wGetProgramResourceIndex;
extern PFNGLGETPROGRAMRESOURCELOCATIONPROC                  gl3wGetProgramResourceLocation;
extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC             gl3wGetProgramResourceLocationIndex;
extern PFNGLGETPROGRAMRESOURCENAMEPROC                      gl3wGetProgramResourceName;
extern PFNGLGETPROGRAMRESOURCEFVNVPROC                      gl3wGetProgramResourcefvNV;
extern PFNGLGETPROGRAMRESOURCEIVPROC                        gl3wGetProgramResourceiv;
extern PFNGLGETPROGRAMSTAGEIVPROC                           gl3wGetProgramStageiv;
extern PFNGLGETPROGRAMIVPROC                                gl3wGetProgramiv;
extern PFNGLGETQUERYBUFFEROBJECTI64VPROC                    gl3wGetQueryBufferObjecti64v;
extern PFNGLGETQUERYBUFFEROBJECTIVPROC                      gl3wGetQueryBufferObjectiv;
extern PFNGLGETQUERYBUFFEROBJECTUI64VPROC                   gl3wGetQueryBufferObjectui64v;
extern PFNGLGETQUERYBUFFEROBJECTUIVPROC                     gl3wGetQueryBufferObjectuiv;
extern PFNGLGETQUERYINDEXEDIVPROC                           gl3wGetQueryIndexediv;
extern PFNGLGETQUERYOBJECTI64VPROC                          gl3wGetQueryObjecti64v;
extern PFNGLGETQUERYOBJECTIVPROC                            gl3wGetQueryObjectiv;
extern PFNGLGETQUERYOBJECTUI64VPROC                         gl3wGetQueryObjectui64v;
extern PFNGLGETQUERYOBJECTUIVPROC                           gl3wGetQueryObjectuiv;
extern PFNGLGETQUERYIVPROC                                  gl3wGetQueryiv;
extern PFNGLGETRENDERBUFFERPARAMETERIVPROC                  gl3wGetRenderbufferParameteriv;
extern PFNGLGETSAMPLERPARAMETERIIVPROC                      gl3wGetSamplerParameterIiv;
extern PFNGLGETSAMPLERPARAMETERIUIVPROC                     gl3wGetSamplerParameterIuiv;
extern PFNGLGETSAMPLERPARAMETERFVPROC                       gl3wGetSamplerParameterfv;
extern PFNGLGETSAMPLERPARAMETERIVPROC                       gl3wGetSamplerParameteriv;
extern PFNGLGETSHADERINFOLOGPROC                            gl3wGetShaderInfoLog;
extern PFNGLGETSHADERPRECISIONFORMATPROC                    gl3wGetShaderPrecisionFormat;
extern PFNGLGETSHADERSOURCEPROC                             gl3wGetShaderSource;
extern PFNGLGETSHADERIVPROC                                 gl3wGetShaderiv;
extern PFNGLGETSTAGEINDEXNVPROC                             gl3wGetStageIndexNV;
extern PFNGLGETSTRINGPROC                                   gl3wGetString;
extern PFNGLGETSTRINGIPROC                                  gl3wGetStringi;
extern PFNGLGETSUBROUTINEINDEXPROC                          gl3wGetSubroutineIndex;
extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC                gl3wGetSubroutineUniformLocation;
extern PFNGLGETSYNCIVPROC                                   gl3wGetSynciv;
extern PFNGLGETTEXIMAGEPROC                                 gl3wGetTexImage;
extern PFNGLGETTEXLEVELPARAMETERFVPROC                      gl3wGetTexLevelParameterfv;
extern PFNGLGETTEXLEVELPARAMETERIVPROC                      gl3wGetTexLevelParameteriv;
extern PFNGLGETTEXPARAMETERIIVPROC                          gl3wGetTexParameterIiv;
extern PFNGLGETTEXPARAMETERIUIVPROC                         gl3wGetTexParameterIuiv;
extern PFNGLGETTEXPARAMETERFVPROC                           gl3wGetTexParameterfv;
extern PFNGLGETTEXPARAMETERIVPROC                           gl3wGetTexParameteriv;
extern PFNGLGETTEXTUREHANDLEARBPROC                         gl3wGetTextureHandleARB;
extern PFNGLGETTEXTUREHANDLENVPROC                          gl3wGetTextureHandleNV;
extern PFNGLGETTEXTUREIMAGEPROC                             gl3wGetTextureImage;
extern PFNGLGETTEXTUREIMAGEEXTPROC                          gl3wGetTextureImageEXT;
extern PFNGLGETTEXTURELEVELPARAMETERFVPROC                  gl3wGetTextureLevelParameterfv;
extern PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC               gl3wGetTextureLevelParameterfvEXT;
extern PFNGLGETTEXTURELEVELPARAMETERIVPROC                  gl3wGetTextureLevelParameteriv;
extern PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC               gl3wGetTextureLevelParameterivEXT;
extern PFNGLGETTEXTUREPARAMETERIIVPROC                      gl3wGetTextureParameterIiv;
extern PFNGLGETTEXTUREPARAMETERIIVEXTPROC                   gl3wGetTextureParameterIivEXT;
extern PFNGLGETTEXTUREPARAMETERIUIVPROC                     gl3wGetTextureParameterIuiv;
extern PFNGLGETTEXTUREPARAMETERIUIVEXTPROC                  gl3wGetTextureParameterIuivEXT;
extern PFNGLGETTEXTUREPARAMETERFVPROC                       gl3wGetTextureParameterfv;
extern PFNGLGETTEXTUREPARAMETERFVEXTPROC                    gl3wGetTextureParameterfvEXT;
extern PFNGLGETTEXTUREPARAMETERIVPROC                       gl3wGetTextureParameteriv;
extern PFNGLGETTEXTUREPARAMETERIVEXTPROC                    gl3wGetTextureParameterivEXT;
extern PFNGLGETTEXTURESAMPLERHANDLEARBPROC                  gl3wGetTextureSamplerHandleARB;
extern PFNGLGETTEXTURESAMPLERHANDLENVPROC                   gl3wGetTextureSamplerHandleNV;
extern PFNGLGETTEXTURESUBIMAGEPROC                          gl3wGetTextureSubImage;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC                 gl3wGetTransformFeedbackVarying;
extern PFNGLGETTRANSFORMFEEDBACKI64_VPROC                   gl3wGetTransformFeedbacki64_v;
extern PFNGLGETTRANSFORMFEEDBACKI_VPROC                     gl3wGetTransformFeedbacki_v;
extern PFNGLGETTRANSFORMFEEDBACKIVPROC                      gl3wGetTransformFeedbackiv;
extern PFNGLGETUNIFORMBLOCKINDEXPROC                        gl3wGetUniformBlockIndex;
extern PFNGLGETUNIFORMINDICESPROC                           gl3wGetUniformIndices;
extern PFNGLGETUNIFORMLOCATIONPROC                          gl3wGetUniformLocation;
extern PFNGLGETUNIFORMSUBROUTINEUIVPROC                     gl3wGetUniformSubroutineuiv;
extern PFNGLGETUNIFORMDVPROC                                gl3wGetUniformdv;
extern PFNGLGETUNIFORMFVPROC                                gl3wGetUniformfv;
extern PFNGLGETUNIFORMI64VARBPROC                           gl3wGetUniformi64vARB;
extern PFNGLGETUNIFORMI64VNVPROC                            gl3wGetUniformi64vNV;
extern PFNGLGETUNIFORMIVPROC                                gl3wGetUniformiv;
extern PFNGLGETUNIFORMUI64VARBPROC                          gl3wGetUniformui64vARB;
extern PFNGLGETUNIFORMUI64VNVPROC                           gl3wGetUniformui64vNV;
extern PFNGLGETUNIFORMUIVPROC                               gl3wGetUniformuiv;
extern PFNGLGETVERTEXARRAYINDEXED64IVPROC                   gl3wGetVertexArrayIndexed64iv;
extern PFNGLGETVERTEXARRAYINDEXEDIVPROC                     gl3wGetVertexArrayIndexediv;
extern PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC                 gl3wGetVertexArrayIntegeri_vEXT;
extern PFNGLGETVERTEXARRAYINTEGERVEXTPROC                   gl3wGetVertexArrayIntegervEXT;
extern PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC                 gl3wGetVertexArrayPointeri_vEXT;
extern PFNGLGETVERTEXARRAYPOINTERVEXTPROC                   gl3wGetVertexArrayPointervEXT;
extern PFNGLGETVERTEXARRAYIVPROC                            gl3wGetVertexArrayiv;
extern PFNGLGETVERTEXATTRIBIIVPROC                          gl3wGetVertexAttribIiv;
extern PFNGLGETVERTEXATTRIBIUIVPROC                         gl3wGetVertexAttribIuiv;
extern PFNGLGETVERTEXATTRIBLDVPROC                          gl3wGetVertexAttribLdv;
extern PFNGLGETVERTEXATTRIBLI64VNVPROC                      gl3wGetVertexAttribLi64vNV;
extern PFNGLGETVERTEXATTRIBLUI64VARBPROC                    gl3wGetVertexAttribLui64vARB;
extern PFNGLGETVERTEXATTRIBLUI64VNVPROC                     gl3wGetVertexAttribLui64vNV;
extern PFNGLGETVERTEXATTRIBPOINTERVPROC                     gl3wGetVertexAttribPointerv;
extern PFNGLGETVERTEXATTRIBDVPROC                           gl3wGetVertexAttribdv;
extern PFNGLGETVERTEXATTRIBFVPROC                           gl3wGetVertexAttribfv;
extern PFNGLGETVERTEXATTRIBIVPROC                           gl3wGetVertexAttribiv;
extern PFNGLGETVKPROCADDRNVPROC                             gl3wGetVkProcAddrNV;
extern PFNGLGETNCOMPRESSEDTEXIMAGEPROC                      gl3wGetnCompressedTexImage;
extern PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC                   gl3wGetnCompressedTexImageARB;
extern PFNGLGETNTEXIMAGEPROC                                gl3wGetnTexImage;
extern PFNGLGETNTEXIMAGEARBPROC                             gl3wGetnTexImageARB;
extern PFNGLGETNUNIFORMDVPROC                               gl3wGetnUniformdv;
extern PFNGLGETNUNIFORMDVARBPROC                            gl3wGetnUniformdvARB;
extern PFNGLGETNUNIFORMFVPROC                               gl3wGetnUniformfv;
extern PFNGLGETNUNIFORMFVARBPROC                            gl3wGetnUniformfvARB;
extern PFNGLGETNUNIFORMI64VARBPROC                          gl3wGetnUniformi64vARB;
extern PFNGLGETNUNIFORMIVPROC                               gl3wGetnUniformiv;
extern PFNGLGETNUNIFORMIVARBPROC                            gl3wGetnUniformivARB;
extern PFNGLGETNUNIFORMUI64VARBPROC                         gl3wGetnUniformui64vARB;
extern PFNGLGETNUNIFORMUIVPROC                              gl3wGetnUniformuiv;
extern PFNGLGETNUNIFORMUIVARBPROC                           gl3wGetnUniformuivARB;
extern PFNGLHINTPROC                                        gl3wHint;
extern PFNGLINDEXFORMATNVPROC                               gl3wIndexFormatNV;
extern PFNGLINSERTEVENTMARKEREXTPROC                        gl3wInsertEventMarkerEXT;
extern PFNGLINTERPOLATEPATHSNVPROC                          gl3wInterpolatePathsNV;
extern PFNGLINVALIDATEBUFFERDATAPROC                        gl3wInvalidateBufferData;
extern PFNGLINVALIDATEBUFFERSUBDATAPROC                     gl3wInvalidateBufferSubData;
extern PFNGLINVALIDATEFRAMEBUFFERPROC                       gl3wInvalidateFramebuffer;
extern PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC              gl3wInvalidateNamedFramebufferData;
extern PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC           gl3wInvalidateNamedFramebufferSubData;
extern PFNGLINVALIDATESUBFRAMEBUFFERPROC                    gl3wInvalidateSubFramebuffer;
extern PFNGLINVALIDATETEXIMAGEPROC                          gl3wInvalidateTexImage;
extern PFNGLINVALIDATETEXSUBIMAGEPROC                       gl3wInvalidateTexSubImage;
extern PFNGLISBUFFERPROC                                    gl3wIsBuffer;
extern PFNGLISBUFFERRESIDENTNVPROC                          gl3wIsBufferResidentNV;
extern PFNGLISCOMMANDLISTNVPROC                             gl3wIsCommandListNV;
extern PFNGLISENABLEDPROC                                   gl3wIsEnabled;
extern PFNGLISENABLEDINDEXEDEXTPROC                         gl3wIsEnabledIndexedEXT;
extern PFNGLISENABLEDIPROC                                  gl3wIsEnabledi;
extern PFNGLISFRAMEBUFFERPROC                               gl3wIsFramebuffer;
extern PFNGLISIMAGEHANDLERESIDENTARBPROC                    gl3wIsImageHandleResidentARB;
extern PFNGLISIMAGEHANDLERESIDENTNVPROC                     gl3wIsImageHandleResidentNV;
extern PFNGLISNAMEDBUFFERRESIDENTNVPROC                     gl3wIsNamedBufferResidentNV;
extern PFNGLISNAMEDSTRINGARBPROC                            gl3wIsNamedStringARB;
extern PFNGLISPATHNVPROC                                    gl3wIsPathNV;
extern PFNGLISPOINTINFILLPATHNVPROC                         gl3wIsPointInFillPathNV;
extern PFNGLISPOINTINSTROKEPATHNVPROC                       gl3wIsPointInStrokePathNV;
extern PFNGLISPROGRAMPROC                                   gl3wIsProgram;
extern PFNGLISPROGRAMPIPELINEPROC                           gl3wIsProgramPipeline;
extern PFNGLISQUERYPROC                                     gl3wIsQuery;
extern PFNGLISRENDERBUFFERPROC                              gl3wIsRenderbuffer;
extern PFNGLISSAMPLERPROC                                   gl3wIsSampler;
extern PFNGLISSHADERPROC                                    gl3wIsShader;
extern PFNGLISSTATENVPROC                                   gl3wIsStateNV;
extern PFNGLISSYNCPROC                                      gl3wIsSync;
extern PFNGLISTEXTUREPROC                                   gl3wIsTexture;
extern PFNGLISTEXTUREHANDLERESIDENTARBPROC                  gl3wIsTextureHandleResidentARB;
extern PFNGLISTEXTUREHANDLERESIDENTNVPROC                   gl3wIsTextureHandleResidentNV;
extern PFNGLISTRANSFORMFEEDBACKPROC                         gl3wIsTransformFeedback;
extern PFNGLISVERTEXARRAYPROC                               gl3wIsVertexArray;
extern PFNGLLABELOBJECTEXTPROC                              gl3wLabelObjectEXT;
extern PFNGLLINEWIDTHPROC                                   gl3wLineWidth;
extern PFNGLLINKPROGRAMPROC                                 gl3wLinkProgram;
extern PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC              gl3wListDrawCommandsStatesClientNV;
extern PFNGLLOGICOPPROC                                     gl3wLogicOp;
extern PFNGLMAKEBUFFERNONRESIDENTNVPROC                     gl3wMakeBufferNonResidentNV;
extern PFNGLMAKEBUFFERRESIDENTNVPROC                        gl3wMakeBufferResidentNV;
extern PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC               gl3wMakeImageHandleNonResidentARB;
extern PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC                gl3wMakeImageHandleNonResidentNV;
extern PFNGLMAKEIMAGEHANDLERESIDENTARBPROC                  gl3wMakeImageHandleResidentARB;
extern PFNGLMAKEIMAGEHANDLERESIDENTNVPROC                   gl3wMakeImageHandleResidentNV;
extern PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC                gl3wMakeNamedBufferNonResidentNV;
extern PFNGLMAKENAMEDBUFFERRESIDENTNVPROC                   gl3wMakeNamedBufferResidentNV;
extern PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC             gl3wMakeTextureHandleNonResidentARB;
extern PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC              gl3wMakeTextureHandleNonResidentNV;
extern PFNGLMAKETEXTUREHANDLERESIDENTARBPROC                gl3wMakeTextureHandleResidentARB;
extern PFNGLMAKETEXTUREHANDLERESIDENTNVPROC                 gl3wMakeTextureHandleResidentNV;
extern PFNGLMAPBUFFERPROC                                   gl3wMapBuffer;
extern PFNGLMAPBUFFERRANGEPROC                              gl3wMapBufferRange;
extern PFNGLMAPNAMEDBUFFERPROC                              gl3wMapNamedBuffer;
extern PFNGLMAPNAMEDBUFFEREXTPROC                           gl3wMapNamedBufferEXT;
extern PFNGLMAPNAMEDBUFFERRANGEPROC                         gl3wMapNamedBufferRange;
extern PFNGLMAPNAMEDBUFFERRANGEEXTPROC                      gl3wMapNamedBufferRangeEXT;
extern PFNGLMATRIXFRUSTUMEXTPROC                            gl3wMatrixFrustumEXT;
extern PFNGLMATRIXLOAD3X2FNVPROC                            gl3wMatrixLoad3x2fNV;
extern PFNGLMATRIXLOAD3X3FNVPROC                            gl3wMatrixLoad3x3fNV;
extern PFNGLMATRIXLOADIDENTITYEXTPROC                       gl3wMatrixLoadIdentityEXT;
extern PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC                   gl3wMatrixLoadTranspose3x3fNV;
extern PFNGLMATRIXLOADTRANSPOSEDEXTPROC                     gl3wMatrixLoadTransposedEXT;
extern PFNGLMATRIXLOADTRANSPOSEFEXTPROC                     gl3wMatrixLoadTransposefEXT;
extern PFNGLMATRIXLOADDEXTPROC                              gl3wMatrixLoaddEXT;
extern PFNGLMATRIXLOADFEXTPROC                              gl3wMatrixLoadfEXT;
extern PFNGLMATRIXMULT3X2FNVPROC                            gl3wMatrixMult3x2fNV;
extern PFNGLMATRIXMULT3X3FNVPROC                            gl3wMatrixMult3x3fNV;
extern PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC                   gl3wMatrixMultTranspose3x3fNV;
extern PFNGLMATRIXMULTTRANSPOSEDEXTPROC                     gl3wMatrixMultTransposedEXT;
extern PFNGLMATRIXMULTTRANSPOSEFEXTPROC                     gl3wMatrixMultTransposefEXT;
extern PFNGLMATRIXMULTDEXTPROC                              gl3wMatrixMultdEXT;
extern PFNGLMATRIXMULTFEXTPROC                              gl3wMatrixMultfEXT;
extern PFNGLMATRIXORTHOEXTPROC                              gl3wMatrixOrthoEXT;
extern PFNGLMATRIXPOPEXTPROC                                gl3wMatrixPopEXT;
extern PFNGLMATRIXPUSHEXTPROC                               gl3wMatrixPushEXT;
extern PFNGLMATRIXROTATEDEXTPROC                            gl3wMatrixRotatedEXT;
extern PFNGLMATRIXROTATEFEXTPROC                            gl3wMatrixRotatefEXT;
extern PFNGLMATRIXSCALEDEXTPROC                             gl3wMatrixScaledEXT;
extern PFNGLMATRIXSCALEFEXTPROC                             gl3wMatrixScalefEXT;
extern PFNGLMATRIXTRANSLATEDEXTPROC                         gl3wMatrixTranslatedEXT;
extern PFNGLMATRIXTRANSLATEFEXTPROC                         gl3wMatrixTranslatefEXT;
extern PFNGLMAXSHADERCOMPILERTHREADSARBPROC                 gl3wMaxShaderCompilerThreadsARB;
extern PFNGLMAXSHADERCOMPILERTHREADSKHRPROC                 gl3wMaxShaderCompilerThreadsKHR;
extern PFNGLMEMORYBARRIERPROC                               gl3wMemoryBarrier;
extern PFNGLMEMORYBARRIERBYREGIONPROC                       gl3wMemoryBarrierByRegion;
extern PFNGLMINSAMPLESHADINGPROC                            gl3wMinSampleShading;
extern PFNGLMINSAMPLESHADINGARBPROC                         gl3wMinSampleShadingARB;
extern PFNGLMULTIDRAWARRAYSPROC                             gl3wMultiDrawArrays;
extern PFNGLMULTIDRAWARRAYSINDIRECTPROC                     gl3wMultiDrawArraysIndirect;
extern PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC      gl3wMultiDrawArraysIndirectBindlessCountNV;
extern PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC           gl3wMultiDrawArraysIndirectBindlessNV;
extern PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC                gl3wMultiDrawArraysIndirectCount;
extern PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC             gl3wMultiDrawArraysIndirectCountARB;
extern PFNGLMULTIDRAWELEMENTSPROC                           gl3wMultiDrawElements;
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC                 gl3wMultiDrawElementsBaseVertex;
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC                   gl3wMultiDrawElementsIndirect;
extern PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC    gl3wMultiDrawElementsIndirectBindlessCountNV;
extern PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC         gl3wMultiDrawElementsIndirectBindlessNV;
extern PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC              gl3wMultiDrawElementsIndirectCount;
extern PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC           gl3wMultiDrawElementsIndirectCountARB;
extern PFNGLMULTITEXBUFFEREXTPROC                           gl3wMultiTexBufferEXT;
extern PFNGLMULTITEXCOORDPOINTEREXTPROC                     gl3wMultiTexCoordPointerEXT;
extern PFNGLMULTITEXENVFEXTPROC                             gl3wMultiTexEnvfEXT;
extern PFNGLMULTITEXENVFVEXTPROC                            gl3wMultiTexEnvfvEXT;
extern PFNGLMULTITEXENVIEXTPROC                             gl3wMultiTexEnviEXT;
extern PFNGLMULTITEXENVIVEXTPROC                            gl3wMultiTexEnvivEXT;
extern PFNGLMULTITEXGENDEXTPROC                             gl3wMultiTexGendEXT;
extern PFNGLMULTITEXGENDVEXTPROC                            gl3wMultiTexGendvEXT;
extern PFNGLMULTITEXGENFEXTPROC                             gl3wMultiTexGenfEXT;
extern PFNGLMULTITEXGENFVEXTPROC                            gl3wMultiTexGenfvEXT;
extern PFNGLMULTITEXGENIEXTPROC                             gl3wMultiTexGeniEXT;
extern PFNGLMULTITEXGENIVEXTPROC                            gl3wMultiTexGenivEXT;
extern PFNGLMULTITEXIMAGE1DEXTPROC                          gl3wMultiTexImage1DEXT;
extern PFNGLMULTITEXIMAGE2DEXTPROC                          gl3wMultiTexImage2DEXT;
extern PFNGLMULTITEXIMAGE3DEXTPROC                          gl3wMultiTexImage3DEXT;
extern PFNGLMULTITEXPARAMETERIIVEXTPROC                     gl3wMultiTexParameterIivEXT;
extern PFNGLMULTITEXPARAMETERIUIVEXTPROC                    gl3wMultiTexParameterIuivEXT;
extern PFNGLMULTITEXPARAMETERFEXTPROC                       gl3wMultiTexParameterfEXT;
extern PFNGLMULTITEXPARAMETERFVEXTPROC                      gl3wMultiTexParameterfvEXT;
extern PFNGLMULTITEXPARAMETERIEXTPROC                       gl3wMultiTexParameteriEXT;
extern PFNGLMULTITEXPARAMETERIVEXTPROC                      gl3wMultiTexParameterivEXT;
extern PFNGLMULTITEXRENDERBUFFEREXTPROC                     gl3wMultiTexRenderbufferEXT;
extern PFNGLMULTITEXSUBIMAGE1DEXTPROC                       gl3wMultiTexSubImage1DEXT;
extern PFNGLMULTITEXSUBIMAGE2DEXTPROC                       gl3wMultiTexSubImage2DEXT;
extern PFNGLMULTITEXSUBIMAGE3DEXTPROC                       gl3wMultiTexSubImage3DEXT;
extern PFNGLNAMEDBUFFERDATAPROC                             gl3wNamedBufferData;
extern PFNGLNAMEDBUFFERDATAEXTPROC                          gl3wNamedBufferDataEXT;
extern PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC                gl3wNamedBufferPageCommitmentARB;
extern PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC                gl3wNamedBufferPageCommitmentEXT;
extern PFNGLNAMEDBUFFERSTORAGEPROC                          gl3wNamedBufferStorage;
extern PFNGLNAMEDBUFFERSTORAGEEXTPROC                       gl3wNamedBufferStorageEXT;
extern PFNGLNAMEDBUFFERSUBDATAPROC                          gl3wNamedBufferSubData;
extern PFNGLNAMEDBUFFERSUBDATAEXTPROC                       gl3wNamedBufferSubDataEXT;
extern PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC                   gl3wNamedCopyBufferSubDataEXT;
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC                  gl3wNamedFramebufferDrawBuffer;
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC                 gl3wNamedFramebufferDrawBuffers;
extern PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC                  gl3wNamedFramebufferParameteri;
extern PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC               gl3wNamedFramebufferParameteriEXT;
extern PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC                  gl3wNamedFramebufferReadBuffer;
extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC                gl3wNamedFramebufferRenderbuffer;
extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC             gl3wNamedFramebufferRenderbufferEXT;
extern PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC        gl3wNamedFramebufferSampleLocationsfvARB;
extern PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC         gl3wNamedFramebufferSampleLocationsfvNV;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREPROC                     gl3wNamedFramebufferTexture;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC                gl3wNamedFramebufferTexture1DEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC                gl3wNamedFramebufferTexture2DEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC                gl3wNamedFramebufferTexture3DEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC                  gl3wNamedFramebufferTextureEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC              gl3wNamedFramebufferTextureFaceEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC                gl3wNamedFramebufferTextureLayer;
extern PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC             gl3wNamedFramebufferTextureLayerEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC             gl3wNamedProgramLocalParameter4dEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC            gl3wNamedProgramLocalParameter4dvEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC             gl3wNamedProgramLocalParameter4fEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC            gl3wNamedProgramLocalParameter4fvEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC            gl3wNamedProgramLocalParameterI4iEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC           gl3wNamedProgramLocalParameterI4ivEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC           gl3wNamedProgramLocalParameterI4uiEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC          gl3wNamedProgramLocalParameterI4uivEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC           gl3wNamedProgramLocalParameters4fvEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC          gl3wNamedProgramLocalParametersI4ivEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC         gl3wNamedProgramLocalParametersI4uivEXT;
extern PFNGLNAMEDPROGRAMSTRINGEXTPROC                       gl3wNamedProgramStringEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEPROC                    gl3wNamedRenderbufferStorage;
extern PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC                 gl3wNamedRenderbufferStorageEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC         gl3wNamedRenderbufferStorageMultisample;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC gl3wNamedRenderbufferStorageMultisampleCoverageEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC      gl3wNamedRenderbufferStorageMultisampleEXT;
extern PFNGLNAMEDSTRINGARBPROC                              gl3wNamedStringARB;
extern PFNGLNORMALFORMATNVPROC                              gl3wNormalFormatNV;
extern PFNGLOBJECTLABELPROC                                 gl3wObjectLabel;
extern PFNGLOBJECTPTRLABELPROC                              gl3wObjectPtrLabel;
extern PFNGLPATCHPARAMETERFVPROC                            gl3wPatchParameterfv;
extern PFNGLPATCHPARAMETERIPROC                             gl3wPatchParameteri;
extern PFNGLPATHCOMMANDSNVPROC                              gl3wPathCommandsNV;
extern PFNGLPATHCOORDSNVPROC                                gl3wPathCoordsNV;
extern PFNGLPATHCOVERDEPTHFUNCNVPROC                        gl3wPathCoverDepthFuncNV;
extern PFNGLPATHDASHARRAYNVPROC                             gl3wPathDashArrayNV;
extern PFNGLPATHGLYPHINDEXARRAYNVPROC                       gl3wPathGlyphIndexArrayNV;
extern PFNGLPATHGLYPHINDEXRANGENVPROC                       gl3wPathGlyphIndexRangeNV;
extern PFNGLPATHGLYPHRANGENVPROC                            gl3wPathGlyphRangeNV;
extern PFNGLPATHGLYPHSNVPROC                                gl3wPathGlyphsNV;
extern PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC                 gl3wPathMemoryGlyphIndexArrayNV;
extern PFNGLPATHPARAMETERFNVPROC                            gl3wPathParameterfNV;
extern PFNGLPATHPARAMETERFVNVPROC                           gl3wPathParameterfvNV;
extern PFNGLPATHPARAMETERINVPROC                            gl3wPathParameteriNV;
extern PFNGLPATHPARAMETERIVNVPROC                           gl3wPathParameterivNV;
extern PFNGLPATHSTENCILDEPTHOFFSETNVPROC                    gl3wPathStencilDepthOffsetNV;
extern PFNGLPATHSTENCILFUNCNVPROC                           gl3wPathStencilFuncNV;
extern PFNGLPATHSTRINGNVPROC                                gl3wPathStringNV;
extern PFNGLPATHSUBCOMMANDSNVPROC                           gl3wPathSubCommandsNV;
extern PFNGLPATHSUBCOORDSNVPROC                             gl3wPathSubCoordsNV;
extern PFNGLPAUSETRANSFORMFEEDBACKPROC                      gl3wPauseTransformFeedback;
extern PFNGLPIXELSTOREFPROC                                 gl3wPixelStoref;
extern PFNGLPIXELSTOREIPROC                                 gl3wPixelStorei;
extern PFNGLPOINTALONGPATHNVPROC                            gl3wPointAlongPathNV;
extern PFNGLPOINTPARAMETERFPROC                             gl3wPointParameterf;
extern PFNGLPOINTPARAMETERFVPROC                            gl3wPointParameterfv;
extern PFNGLPOINTPARAMETERIPROC                             gl3wPointParameteri;
extern PFNGLPOINTPARAMETERIVPROC                            gl3wPointParameteriv;
extern PFNGLPOINTSIZEPROC                                   gl3wPointSize;
extern PFNGLPOLYGONMODEPROC                                 gl3wPolygonMode;
extern PFNGLPOLYGONOFFSETPROC                               gl3wPolygonOffset;
extern PFNGLPOLYGONOFFSETCLAMPPROC                          gl3wPolygonOffsetClamp;
extern PFNGLPOLYGONOFFSETCLAMPEXTPROC                       gl3wPolygonOffsetClampEXT;
extern PFNGLPOPDEBUGGROUPPROC                               gl3wPopDebugGroup;
extern PFNGLPOPGROUPMARKEREXTPROC                           gl3wPopGroupMarkerEXT;
extern PFNGLPRIMITIVEBOUNDINGBOXARBPROC                     gl3wPrimitiveBoundingBoxARB;
extern PFNGLPRIMITIVERESTARTINDEXPROC                       gl3wPrimitiveRestartIndex;
extern PFNGLPROGRAMBINARYPROC                               gl3wProgramBinary;
extern PFNGLPROGRAMPARAMETERIPROC                           gl3wProgramParameteri;
extern PFNGLPROGRAMPARAMETERIARBPROC                        gl3wProgramParameteriARB;
extern PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC               gl3wProgramPathFragmentInputGenNV;
extern PFNGLPROGRAMUNIFORM1DPROC                            gl3wProgramUniform1d;
extern PFNGLPROGRAMUNIFORM1DEXTPROC                         gl3wProgramUniform1dEXT;
extern PFNGLPROGRAMUNIFORM1DVPROC                           gl3wProgramUniform1dv;
extern PFNGLPROGRAMUNIFORM1DVEXTPROC                        gl3wProgramUniform1dvEXT;
extern PFNGLPROGRAMUNIFORM1FPROC                            gl3wProgramUniform1f;
extern PFNGLPROGRAMUNIFORM1FEXTPROC                         gl3wProgramUniform1fEXT;
extern PFNGLPROGRAMUNIFORM1FVPROC                           gl3wProgramUniform1fv;
extern PFNGLPROGRAMUNIFORM1FVEXTPROC                        gl3wProgramUniform1fvEXT;
extern PFNGLPROGRAMUNIFORM1IPROC                            gl3wProgramUniform1i;
extern PFNGLPROGRAMUNIFORM1I64ARBPROC                       gl3wProgramUniform1i64ARB;
extern PFNGLPROGRAMUNIFORM1I64NVPROC                        gl3wProgramUniform1i64NV;
extern PFNGLPROGRAMUNIFORM1I64VARBPROC                      gl3wProgramUniform1i64vARB;
extern PFNGLPROGRAMUNIFORM1I64VNVPROC                       gl3wProgramUniform1i64vNV;
extern PFNGLPROGRAMUNIFORM1IEXTPROC                         gl3wProgramUniform1iEXT;
extern PFNGLPROGRAMUNIFORM1IVPROC                           gl3wProgramUniform1iv;
extern PFNGLPROGRAMUNIFORM1IVEXTPROC                        gl3wProgramUniform1ivEXT;
extern PFNGLPROGRAMUNIFORM1UIPROC                           gl3wProgramUniform1ui;
extern PFNGLPROGRAMUNIFORM1UI64ARBPROC                      gl3wProgramUniform1ui64ARB;
extern PFNGLPROGRAMUNIFORM1UI64NVPROC                       gl3wProgramUniform1ui64NV;
extern PFNGLPROGRAMUNIFORM1UI64VARBPROC                     gl3wProgramUniform1ui64vARB;
extern PFNGLPROGRAMUNIFORM1UI64VNVPROC                      gl3wProgramUniform1ui64vNV;
extern PFNGLPROGRAMUNIFORM1UIEXTPROC                        gl3wProgramUniform1uiEXT;
extern PFNGLPROGRAMUNIFORM1UIVPROC                          gl3wProgramUniform1uiv;
extern PFNGLPROGRAMUNIFORM1UIVEXTPROC                       gl3wProgramUniform1uivEXT;
extern PFNGLPROGRAMUNIFORM2DPROC                            gl3wProgramUniform2d;
extern PFNGLPROGRAMUNIFORM2DEXTPROC                         gl3wProgramUniform2dEXT;
extern PFNGLPROGRAMUNIFORM2DVPROC                           gl3wProgramUniform2dv;
extern PFNGLPROGRAMUNIFORM2DVEXTPROC                        gl3wProgramUniform2dvEXT;
extern PFNGLPROGRAMUNIFORM2FPROC                            gl3wProgramUniform2f;
extern PFNGLPROGRAMUNIFORM2FEXTPROC                         gl3wProgramUniform2fEXT;
extern PFNGLPROGRAMUNIFORM2FVPROC                           gl3wProgramUniform2fv;
extern PFNGLPROGRAMUNIFORM2FVEXTPROC                        gl3wProgramUniform2fvEXT;
extern PFNGLPROGRAMUNIFORM2IPROC                            gl3wProgramUniform2i;
extern PFNGLPROGRAMUNIFORM2I64ARBPROC                       gl3wProgramUniform2i64ARB;
extern PFNGLPROGRAMUNIFORM2I64NVPROC                        gl3wProgramUniform2i64NV;
extern PFNGLPROGRAMUNIFORM2I64VARBPROC                      gl3wProgramUniform2i64vARB;
extern PFNGLPROGRAMUNIFORM2I64VNVPROC                       gl3wProgramUniform2i64vNV;
extern PFNGLPROGRAMUNIFORM2IEXTPROC                         gl3wProgramUniform2iEXT;
extern PFNGLPROGRAMUNIFORM2IVPROC                           gl3wProgramUniform2iv;
extern PFNGLPROGRAMUNIFORM2IVEXTPROC                        gl3wProgramUniform2ivEXT;
extern PFNGLPROGRAMUNIFORM2UIPROC                           gl3wProgramUniform2ui;
extern PFNGLPROGRAMUNIFORM2UI64ARBPROC                      gl3wProgramUniform2ui64ARB;
extern PFNGLPROGRAMUNIFORM2UI64NVPROC                       gl3wProgramUniform2ui64NV;
extern PFNGLPROGRAMUNIFORM2UI64VARBPROC                     gl3wProgramUniform2ui64vARB;
extern PFNGLPROGRAMUNIFORM2UI64VNVPROC                      gl3wProgramUniform2ui64vNV;
extern PFNGLPROGRAMUNIFORM2UIEXTPROC                        gl3wProgramUniform2uiEXT;
extern PFNGLPROGRAMUNIFORM2UIVPROC                          gl3wProgramUniform2uiv;
extern PFNGLPROGRAMUNIFORM2UIVEXTPROC                       gl3wProgramUniform2uivEXT;
extern PFNGLPROGRAMUNIFORM3DPROC                            gl3wProgramUniform3d;
extern PFNGLPROGRAMUNIFORM3DEXTPROC                         gl3wProgramUniform3dEXT;
extern PFNGLPROGRAMUNIFORM3DVPROC                           gl3wProgramUniform3dv;
extern PFNGLPROGRAMUNIFORM3DVEXTPROC                        gl3wProgramUniform3dvEXT;
extern PFNGLPROGRAMUNIFORM3FPROC                            gl3wProgramUniform3f;
extern PFNGLPROGRAMUNIFORM3FEXTPROC                         gl3wProgramUniform3fEXT;
extern PFNGLPROGRAMUNIFORM3FVPROC                           gl3wProgramUniform3fv;
extern PFNGLPROGRAMUNIFORM3FVEXTPROC                        gl3wProgramUniform3fvEXT;
extern PFNGLPROGRAMUNIFORM3IPROC                            gl3wProgramUniform3i;
extern PFNGLPROGRAMUNIFORM3I64ARBPROC                       gl3wProgramUniform3i64ARB;
extern PFNGLPROGRAMUNIFORM3I64NVPROC                        gl3wProgramUniform3i64NV;
extern PFNGLPROGRAMUNIFORM3I64VARBPROC                      gl3wProgramUniform3i64vARB;
extern PFNGLPROGRAMUNIFORM3I64VNVPROC                       gl3wProgramUniform3i64vNV;
extern PFNGLPROGRAMUNIFORM3IEXTPROC                         gl3wProgramUniform3iEXT;
extern PFNGLPROGRAMUNIFORM3IVPROC                           gl3wProgramUniform3iv;
extern PFNGLPROGRAMUNIFORM3IVEXTPROC                        gl3wProgramUniform3ivEXT;
extern PFNGLPROGRAMUNIFORM3UIPROC                           gl3wProgramUniform3ui;
extern PFNGLPROGRAMUNIFORM3UI64ARBPROC                      gl3wProgramUniform3ui64ARB;
extern PFNGLPROGRAMUNIFORM3UI64NVPROC                       gl3wProgramUniform3ui64NV;
extern PFNGLPROGRAMUNIFORM3UI64VARBPROC                     gl3wProgramUniform3ui64vARB;
extern PFNGLPROGRAMUNIFORM3UI64VNVPROC                      gl3wProgramUniform3ui64vNV;
extern PFNGLPROGRAMUNIFORM3UIEXTPROC                        gl3wProgramUniform3uiEXT;
extern PFNGLPROGRAMUNIFORM3UIVPROC                          gl3wProgramUniform3uiv;
extern PFNGLPROGRAMUNIFORM3UIVEXTPROC                       gl3wProgramUniform3uivEXT;
extern PFNGLPROGRAMUNIFORM4DPROC                            gl3wProgramUniform4d;
extern PFNGLPROGRAMUNIFORM4DEXTPROC                         gl3wProgramUniform4dEXT;
extern PFNGLPROGRAMUNIFORM4DVPROC                           gl3wProgramUniform4dv;
extern PFNGLPROGRAMUNIFORM4DVEXTPROC                        gl3wProgramUniform4dvEXT;
extern PFNGLPROGRAMUNIFORM4FPROC                            gl3wProgramUniform4f;
extern PFNGLPROGRAMUNIFORM4FEXTPROC                         gl3wProgramUniform4fEXT;
extern PFNGLPROGRAMUNIFORM4FVPROC                           gl3wProgramUniform4fv;
extern PFNGLPROGRAMUNIFORM4FVEXTPROC                        gl3wProgramUniform4fvEXT;
extern PFNGLPROGRAMUNIFORM4IPROC                            gl3wProgramUniform4i;
extern PFNGLPROGRAMUNIFORM4I64ARBPROC                       gl3wProgramUniform4i64ARB;
extern PFNGLPROGRAMUNIFORM4I64NVPROC                        gl3wProgramUniform4i64NV;
extern PFNGLPROGRAMUNIFORM4I64VARBPROC                      gl3wProgramUniform4i64vARB;
extern PFNGLPROGRAMUNIFORM4I64VNVPROC                       gl3wProgramUniform4i64vNV;
extern PFNGLPROGRAMUNIFORM4IEXTPROC                         gl3wProgramUniform4iEXT;
extern PFNGLPROGRAMUNIFORM4IVPROC                           gl3wProgramUniform4iv;
extern PFNGLPROGRAMUNIFORM4IVEXTPROC                        gl3wProgramUniform4ivEXT;
extern PFNGLPROGRAMUNIFORM4UIPROC                           gl3wProgramUniform4ui;
extern PFNGLPROGRAMUNIFORM4UI64ARBPROC                      gl3wProgramUniform4ui64ARB;
extern PFNGLPROGRAMUNIFORM4UI64NVPROC                       gl3wProgramUniform4ui64NV;
extern PFNGLPROGRAMUNIFORM4UI64VARBPROC                     gl3wProgramUniform4ui64vARB;
extern PFNGLPROGRAMUNIFORM4UI64VNVPROC                      gl3wProgramUniform4ui64vNV;
extern PFNGLPROGRAMUNIFORM4UIEXTPROC                        gl3wProgramUniform4uiEXT;
extern PFNGLPROGRAMUNIFORM4UIVPROC                          gl3wProgramUniform4uiv;
extern PFNGLPROGRAMUNIFORM4UIVEXTPROC                       gl3wProgramUniform4uivEXT;
extern PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC                 gl3wProgramUniformHandleui64ARB;
extern PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC                  gl3wProgramUniformHandleui64NV;
extern PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC                gl3wProgramUniformHandleui64vARB;
extern PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC                 gl3wProgramUniformHandleui64vNV;
extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC                     gl3wProgramUniformMatrix2dv;
extern PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC                  gl3wProgramUniformMatrix2dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC                     gl3wProgramUniformMatrix2fv;
extern PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC                  gl3wProgramUniformMatrix2fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC                   gl3wProgramUniformMatrix2x3dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC                gl3wProgramUniformMatrix2x3dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC                   gl3wProgramUniformMatrix2x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC                gl3wProgramUniformMatrix2x3fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC                   gl3wProgramUniformMatrix2x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC                gl3wProgramUniformMatrix2x4dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC                   gl3wProgramUniformMatrix2x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC                gl3wProgramUniformMatrix2x4fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC                     gl3wProgramUniformMatrix3dv;
extern PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC                  gl3wProgramUniformMatrix3dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC                     gl3wProgramUniformMatrix3fv;
extern PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC                  gl3wProgramUniformMatrix3fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC                   gl3wProgramUniformMatrix3x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC                gl3wProgramUniformMatrix3x2dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC                   gl3wProgramUniformMatrix3x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC                gl3wProgramUniformMatrix3x2fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC                   gl3wProgramUniformMatrix3x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC                gl3wProgramUniformMatrix3x4dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC                   gl3wProgramUniformMatrix3x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC                gl3wProgramUniformMatrix3x4fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC                     gl3wProgramUniformMatrix4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC                  gl3wProgramUniformMatrix4dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC                     gl3wProgramUniformMatrix4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC                  gl3wProgramUniformMatrix4fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC                   gl3wProgramUniformMatrix4x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC                gl3wProgramUniformMatrix4x2dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC                   gl3wProgramUniformMatrix4x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC                gl3wProgramUniformMatrix4x2fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC                   gl3wProgramUniformMatrix4x3dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC                gl3wProgramUniformMatrix4x3dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC                   gl3wProgramUniformMatrix4x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC                gl3wProgramUniformMatrix4x3fvEXT;
extern PFNGLPROGRAMUNIFORMUI64NVPROC                        gl3wProgramUniformui64NV;
extern PFNGLPROGRAMUNIFORMUI64VNVPROC                       gl3wProgramUniformui64vNV;
extern PFNGLPROVOKINGVERTEXPROC                             gl3wProvokingVertex;
extern PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC                  gl3wPushClientAttribDefaultEXT;
extern PFNGLPUSHDEBUGGROUPPROC                              gl3wPushDebugGroup;
extern PFNGLPUSHGROUPMARKEREXTPROC                          gl3wPushGroupMarkerEXT;
extern PFNGLQUERYCOUNTERPROC                                gl3wQueryCounter;
extern PFNGLRASTERSAMPLESEXTPROC                            gl3wRasterSamplesEXT;
extern PFNGLREADBUFFERPROC                                  gl3wReadBuffer;
extern PFNGLREADPIXELSPROC                                  gl3wReadPixels;
extern PFNGLREADNPIXELSPROC                                 gl3wReadnPixels;
extern PFNGLREADNPIXELSARBPROC                              gl3wReadnPixelsARB;
extern PFNGLRELEASESHADERCOMPILERPROC                       gl3wReleaseShaderCompiler;
extern PFNGLRENDERBUFFERSTORAGEPROC                         gl3wRenderbufferStorage;
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC              gl3wRenderbufferStorageMultisample;
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC    gl3wRenderbufferStorageMultisampleCoverageNV;
extern PFNGLRESOLVEDEPTHVALUESNVPROC                        gl3wResolveDepthValuesNV;
extern PFNGLRESUMETRANSFORMFEEDBACKPROC                     gl3wResumeTransformFeedback;
extern PFNGLSAMPLECOVERAGEPROC                              gl3wSampleCoverage;
extern PFNGLSAMPLEMASKIPROC                                 gl3wSampleMaski;
extern PFNGLSAMPLERPARAMETERIIVPROC                         gl3wSamplerParameterIiv;
extern PFNGLSAMPLERPARAMETERIUIVPROC                        gl3wSamplerParameterIuiv;
extern PFNGLSAMPLERPARAMETERFPROC                           gl3wSamplerParameterf;
extern PFNGLSAMPLERPARAMETERFVPROC                          gl3wSamplerParameterfv;
extern PFNGLSAMPLERPARAMETERIPROC                           gl3wSamplerParameteri;
extern PFNGLSAMPLERPARAMETERIVPROC                          gl3wSamplerParameteriv;
extern PFNGLSCISSORPROC                                     gl3wScissor;
extern PFNGLSCISSORARRAYVPROC                               gl3wScissorArrayv;
extern PFNGLSCISSORINDEXEDPROC                              gl3wScissorIndexed;
extern PFNGLSCISSORINDEXEDVPROC                             gl3wScissorIndexedv;
extern PFNGLSECONDARYCOLORFORMATNVPROC                      gl3wSecondaryColorFormatNV;
extern PFNGLSELECTPERFMONITORCOUNTERSAMDPROC                gl3wSelectPerfMonitorCountersAMD;
extern PFNGLSHADERBINARYPROC                                gl3wShaderBinary;
extern PFNGLSHADERSOURCEPROC                                gl3wShaderSource;
extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC                   gl3wShaderStorageBlockBinding;
extern PFNGLSIGNALVKFENCENVPROC                             gl3wSignalVkFenceNV;
extern PFNGLSIGNALVKSEMAPHORENVPROC                         gl3wSignalVkSemaphoreNV;
extern PFNGLSPECIALIZESHADERPROC                            gl3wSpecializeShader;
extern PFNGLSPECIALIZESHADERARBPROC                         gl3wSpecializeShaderARB;
extern PFNGLSTATECAPTURENVPROC                              gl3wStateCaptureNV;
extern PFNGLSTENCILFILLPATHINSTANCEDNVPROC                  gl3wStencilFillPathInstancedNV;
extern PFNGLSTENCILFILLPATHNVPROC                           gl3wStencilFillPathNV;
extern PFNGLSTENCILFUNCPROC                                 gl3wStencilFunc;
extern PFNGLSTENCILFUNCSEPARATEPROC                         gl3wStencilFuncSeparate;
extern PFNGLSTENCILMASKPROC                                 gl3wStencilMask;
extern PFNGLSTENCILMASKSEPARATEPROC                         gl3wStencilMaskSeparate;
extern PFNGLSTENCILOPPROC                                   gl3wStencilOp;
extern PFNGLSTENCILOPSEPARATEPROC                           gl3wStencilOpSeparate;
extern PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC                gl3wStencilStrokePathInstancedNV;
extern PFNGLSTENCILSTROKEPATHNVPROC                         gl3wStencilStrokePathNV;
extern PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC         gl3wStencilThenCoverFillPathInstancedNV;
extern PFNGLSTENCILTHENCOVERFILLPATHNVPROC                  gl3wStencilThenCoverFillPathNV;
extern PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC       gl3wStencilThenCoverStrokePathInstancedNV;
extern PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC                gl3wStencilThenCoverStrokePathNV;
extern PFNGLSUBPIXELPRECISIONBIASNVPROC                     gl3wSubpixelPrecisionBiasNV;
extern PFNGLTEXBUFFERPROC                                   gl3wTexBuffer;
extern PFNGLTEXBUFFERARBPROC                                gl3wTexBufferARB;
extern PFNGLTEXBUFFERRANGEPROC                              gl3wTexBufferRange;
extern PFNGLTEXCOORDFORMATNVPROC                            gl3wTexCoordFormatNV;
extern PFNGLTEXIMAGE1DPROC                                  gl3wTexImage1D;
extern PFNGLTEXIMAGE2DPROC                                  gl3wTexImage2D;
extern PFNGLTEXIMAGE2DMULTISAMPLEPROC                       gl3wTexImage2DMultisample;
extern PFNGLTEXIMAGE3DPROC                                  gl3wTexImage3D;
extern PFNGLTEXIMAGE3DMULTISAMPLEPROC                       gl3wTexImage3DMultisample;
extern PFNGLTEXPAGECOMMITMENTARBPROC                        gl3wTexPageCommitmentARB;
extern PFNGLTEXPARAMETERIIVPROC                             gl3wTexParameterIiv;
extern PFNGLTEXPARAMETERIUIVPROC                            gl3wTexParameterIuiv;
extern PFNGLTEXPARAMETERFPROC                               gl3wTexParameterf;
extern PFNGLTEXPARAMETERFVPROC                              gl3wTexParameterfv;
extern PFNGLTEXPARAMETERIPROC                               gl3wTexParameteri;
extern PFNGLTEXPARAMETERIVPROC                              gl3wTexParameteriv;
extern PFNGLTEXSTORAGE1DPROC                                gl3wTexStorage1D;
extern PFNGLTEXSTORAGE2DPROC                                gl3wTexStorage2D;
extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC                     gl3wTexStorage2DMultisample;
extern PFNGLTEXSTORAGE3DPROC                                gl3wTexStorage3D;
extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC                     gl3wTexStorage3DMultisample;
extern PFNGLTEXSUBIMAGE1DPROC                               gl3wTexSubImage1D;
extern PFNGLTEXSUBIMAGE2DPROC                               gl3wTexSubImage2D;
extern PFNGLTEXSUBIMAGE3DPROC                               gl3wTexSubImage3D;
extern PFNGLTEXTUREBARRIERPROC                              gl3wTextureBarrier;
extern PFNGLTEXTUREBARRIERNVPROC                            gl3wTextureBarrierNV;
extern PFNGLTEXTUREBUFFERPROC                               gl3wTextureBuffer;
extern PFNGLTEXTUREBUFFEREXTPROC                            gl3wTextureBufferEXT;
extern PFNGLTEXTUREBUFFERRANGEPROC                          gl3wTextureBufferRange;
extern PFNGLTEXTUREBUFFERRANGEEXTPROC                       gl3wTextureBufferRangeEXT;
extern PFNGLTEXTUREIMAGE1DEXTPROC                           gl3wTextureImage1DEXT;
extern PFNGLTEXTUREIMAGE2DEXTPROC                           gl3wTextureImage2DEXT;
extern PFNGLTEXTUREIMAGE3DEXTPROC                           gl3wTextureImage3DEXT;
extern PFNGLTEXTUREPAGECOMMITMENTEXTPROC                    gl3wTexturePageCommitmentEXT;
extern PFNGLTEXTUREPARAMETERIIVPROC                         gl3wTextureParameterIiv;
extern PFNGLTEXTUREPARAMETERIIVEXTPROC                      gl3wTextureParameterIivEXT;
extern PFNGLTEXTUREPARAMETERIUIVPROC                        gl3wTextureParameterIuiv;
extern PFNGLTEXTUREPARAMETERIUIVEXTPROC                     gl3wTextureParameterIuivEXT;
extern PFNGLTEXTUREPARAMETERFPROC                           gl3wTextureParameterf;
extern PFNGLTEXTUREPARAMETERFEXTPROC                        gl3wTextureParameterfEXT;
extern PFNGLTEXTUREPARAMETERFVPROC                          gl3wTextureParameterfv;
extern PFNGLTEXTUREPARAMETERFVEXTPROC                       gl3wTextureParameterfvEXT;
extern PFNGLTEXTUREPARAMETERIPROC                           gl3wTextureParameteri;
extern PFNGLTEXTUREPARAMETERIEXTPROC                        gl3wTextureParameteriEXT;
extern PFNGLTEXTUREPARAMETERIVPROC                          gl3wTextureParameteriv;
extern PFNGLTEXTUREPARAMETERIVEXTPROC                       gl3wTextureParameterivEXT;
extern PFNGLTEXTURERENDERBUFFEREXTPROC                      gl3wTextureRenderbufferEXT;
extern PFNGLTEXTURESTORAGE1DPROC                            gl3wTextureStorage1D;
extern PFNGLTEXTURESTORAGE1DEXTPROC                         gl3wTextureStorage1DEXT;
extern PFNGLTEXTURESTORAGE2DPROC                            gl3wTextureStorage2D;
extern PFNGLTEXTURESTORAGE2DEXTPROC                         gl3wTextureStorage2DEXT;
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC                 gl3wTextureStorage2DMultisample;
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC              gl3wTextureStorage2DMultisampleEXT;
extern PFNGLTEXTURESTORAGE3DPROC                            gl3wTextureStorage3D;
extern PFNGLTEXTURESTORAGE3DEXTPROC                         gl3wTextureStorage3DEXT;
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC                 gl3wTextureStorage3DMultisample;
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC              gl3wTextureStorage3DMultisampleEXT;
extern PFNGLTEXTURESUBIMAGE1DPROC                           gl3wTextureSubImage1D;
extern PFNGLTEXTURESUBIMAGE1DEXTPROC                        gl3wTextureSubImage1DEXT;
extern PFNGLTEXTURESUBIMAGE2DPROC                           gl3wTextureSubImage2D;
extern PFNGLTEXTURESUBIMAGE2DEXTPROC                        gl3wTextureSubImage2DEXT;
extern PFNGLTEXTURESUBIMAGE3DPROC                           gl3wTextureSubImage3D;
extern PFNGLTEXTURESUBIMAGE3DEXTPROC                        gl3wTextureSubImage3DEXT;
extern PFNGLTEXTUREVIEWPROC                                 gl3wTextureView;
extern PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC                 gl3wTransformFeedbackBufferBase;
extern PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC                gl3wTransformFeedbackBufferRange;
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC                   gl3wTransformFeedbackVaryings;
extern PFNGLTRANSFORMPATHNVPROC                             gl3wTransformPathNV;
extern PFNGLUNIFORM1DPROC                                   gl3wUniform1d;
extern PFNGLUNIFORM1DVPROC                                  gl3wUniform1dv;
extern PFNGLUNIFORM1FPROC                                   gl3wUniform1f;
extern PFNGLUNIFORM1FVPROC                                  gl3wUniform1fv;
extern PFNGLUNIFORM1IPROC                                   gl3wUniform1i;
extern PFNGLUNIFORM1I64ARBPROC                              gl3wUniform1i64ARB;
extern PFNGLUNIFORM1I64NVPROC                               gl3wUniform1i64NV;
extern PFNGLUNIFORM1I64VARBPROC                             gl3wUniform1i64vARB;
extern PFNGLUNIFORM1I64VNVPROC                              gl3wUniform1i64vNV;
extern PFNGLUNIFORM1IVPROC                                  gl3wUniform1iv;
extern PFNGLUNIFORM1UIPROC                                  gl3wUniform1ui;
extern PFNGLUNIFORM1UI64ARBPROC                             gl3wUniform1ui64ARB;
extern PFNGLUNIFORM1UI64NVPROC                              gl3wUniform1ui64NV;
extern PFNGLUNIFORM1UI64VARBPROC                            gl3wUniform1ui64vARB;
extern PFNGLUNIFORM1UI64VNVPROC                             gl3wUniform1ui64vNV;
extern PFNGLUNIFORM1UIVPROC                                 gl3wUniform1uiv;
extern PFNGLUNIFORM2DPROC                                   gl3wUniform2d;
extern PFNGLUNIFORM2DVPROC                                  gl3wUniform2dv;
extern PFNGLUNIFORM2FPROC                                   gl3wUniform2f;
extern PFNGLUNIFORM2FVPROC                                  gl3wUniform2fv;
extern PFNGLUNIFORM2IPROC                                   gl3wUniform2i;
extern PFNGLUNIFORM2I64ARBPROC                              gl3wUniform2i64ARB;
extern PFNGLUNIFORM2I64NVPROC                               gl3wUniform2i64NV;
extern PFNGLUNIFORM2I64VARBPROC                             gl3wUniform2i64vARB;
extern PFNGLUNIFORM2I64VNVPROC                              gl3wUniform2i64vNV;
extern PFNGLUNIFORM2IVPROC                                  gl3wUniform2iv;
extern PFNGLUNIFORM2UIPROC                                  gl3wUniform2ui;
extern PFNGLUNIFORM2UI64ARBPROC                             gl3wUniform2ui64ARB;
extern PFNGLUNIFORM2UI64NVPROC                              gl3wUniform2ui64NV;
extern PFNGLUNIFORM2UI64VARBPROC                            gl3wUniform2ui64vARB;
extern PFNGLUNIFORM2UI64VNVPROC                             gl3wUniform2ui64vNV;
extern PFNGLUNIFORM2UIVPROC                                 gl3wUniform2uiv;
extern PFNGLUNIFORM3DPROC                                   gl3wUniform3d;
extern PFNGLUNIFORM3DVPROC                                  gl3wUniform3dv;
extern PFNGLUNIFORM3FPROC                                   gl3wUniform3f;
extern PFNGLUNIFORM3FVPROC                                  gl3wUniform3fv;
extern PFNGLUNIFORM3IPROC                                   gl3wUniform3i;
extern PFNGLUNIFORM3I64ARBPROC                              gl3wUniform3i64ARB;
extern PFNGLUNIFORM3I64NVPROC                               gl3wUniform3i64NV;
extern PFNGLUNIFORM3I64VARBPROC                             gl3wUniform3i64vARB;
extern PFNGLUNIFORM3I64VNVPROC                              gl3wUniform3i64vNV;
extern PFNGLUNIFORM3IVPROC                                  gl3wUniform3iv;
extern PFNGLUNIFORM3UIPROC                                  gl3wUniform3ui;
extern PFNGLUNIFORM3UI64ARBPROC                             gl3wUniform3ui64ARB;
extern PFNGLUNIFORM3UI64NVPROC                              gl3wUniform3ui64NV;
extern PFNGLUNIFORM3UI64VARBPROC                            gl3wUniform3ui64vARB;
extern PFNGLUNIFORM3UI64VNVPROC                             gl3wUniform3ui64vNV;
extern PFNGLUNIFORM3UIVPROC                                 gl3wUniform3uiv;
extern PFNGLUNIFORM4DPROC                                   gl3wUniform4d;
extern PFNGLUNIFORM4DVPROC                                  gl3wUniform4dv;
extern PFNGLUNIFORM4FPROC                                   gl3wUniform4f;
extern PFNGLUNIFORM4FVPROC                                  gl3wUniform4fv;
extern PFNGLUNIFORM4IPROC                                   gl3wUniform4i;
extern PFNGLUNIFORM4I64ARBPROC                              gl3wUniform4i64ARB;
extern PFNGLUNIFORM4I64NVPROC                               gl3wUniform4i64NV;
extern PFNGLUNIFORM4I64VARBPROC                             gl3wUniform4i64vARB;
extern PFNGLUNIFORM4I64VNVPROC                              gl3wUniform4i64vNV;
extern PFNGLUNIFORM4IVPROC                                  gl3wUniform4iv;
extern PFNGLUNIFORM4UIPROC                                  gl3wUniform4ui;
extern PFNGLUNIFORM4UI64ARBPROC                             gl3wUniform4ui64ARB;
extern PFNGLUNIFORM4UI64NVPROC                              gl3wUniform4ui64NV;
extern PFNGLUNIFORM4UI64VARBPROC                            gl3wUniform4ui64vARB;
extern PFNGLUNIFORM4UI64VNVPROC                             gl3wUniform4ui64vNV;
extern PFNGLUNIFORM4UIVPROC                                 gl3wUniform4uiv;
extern PFNGLUNIFORMBLOCKBINDINGPROC                         gl3wUniformBlockBinding;
extern PFNGLUNIFORMHANDLEUI64ARBPROC                        gl3wUniformHandleui64ARB;
extern PFNGLUNIFORMHANDLEUI64NVPROC                         gl3wUniformHandleui64NV;
extern PFNGLUNIFORMHANDLEUI64VARBPROC                       gl3wUniformHandleui64vARB;
extern PFNGLUNIFORMHANDLEUI64VNVPROC                        gl3wUniformHandleui64vNV;
extern PFNGLUNIFORMMATRIX2DVPROC                            gl3wUniformMatrix2dv;
extern PFNGLUNIFORMMATRIX2FVPROC                            gl3wUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX2X3DVPROC                          gl3wUniformMatrix2x3dv;
extern PFNGLUNIFORMMATRIX2X3FVPROC                          gl3wUniformMatrix2x3fv;
extern PFNGLUNIFORMMATRIX2X4DVPROC                          gl3wUniformMatrix2x4dv;
extern PFNGLUNIFORMMATRIX2X4FVPROC                          gl3wUniformMatrix2x4fv;
extern PFNGLUNIFORMMATRIX3DVPROC                            gl3wUniformMatrix3dv;
extern PFNGLUNIFORMMATRIX3FVPROC                            gl3wUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX3X2DVPROC                          gl3wUniformMatrix3x2dv;
extern PFNGLUNIFORMMATRIX3X2FVPROC                          gl3wUniformMatrix3x2fv;
extern PFNGLUNIFORMMATRIX3X4DVPROC                          gl3wUniformMatrix3x4dv;
extern PFNGLUNIFORMMATRIX3X4FVPROC                          gl3wUniformMatrix3x4fv;
extern PFNGLUNIFORMMATRIX4DVPROC                            gl3wUniformMatrix4dv;
extern PFNGLUNIFORMMATRIX4FVPROC                            gl3wUniformMatrix4fv;
extern PFNGLUNIFORMMATRIX4X2DVPROC                          gl3wUniformMatrix4x2dv;
extern PFNGLUNIFORMMATRIX4X2FVPROC                          gl3wUniformMatrix4x2fv;
extern PFNGLUNIFORMMATRIX4X3DVPROC                          gl3wUniformMatrix4x3dv;
extern PFNGLUNIFORMMATRIX4X3FVPROC                          gl3wUniformMatrix4x3fv;
extern PFNGLUNIFORMSUBROUTINESUIVPROC                       gl3wUniformSubroutinesuiv;
extern PFNGLUNIFORMUI64NVPROC                               gl3wUniformui64NV;
extern PFNGLUNIFORMUI64VNVPROC                              gl3wUniformui64vNV;
extern PFNGLUNMAPBUFFERPROC                                 gl3wUnmapBuffer;
extern PFNGLUNMAPNAMEDBUFFERPROC                            gl3wUnmapNamedBuffer;
extern PFNGLUNMAPNAMEDBUFFEREXTPROC                         gl3wUnmapNamedBufferEXT;
extern PFNGLUSEPROGRAMPROC                                  gl3wUseProgram;
extern PFNGLUSEPROGRAMSTAGESPROC                            gl3wUseProgramStages;
extern PFNGLUSESHADERPROGRAMEXTPROC                         gl3wUseShaderProgramEXT;
extern PFNGLVALIDATEPROGRAMPROC                             gl3wValidateProgram;
extern PFNGLVALIDATEPROGRAMPIPELINEPROC                     gl3wValidateProgramPipeline;
extern PFNGLVERTEXARRAYATTRIBBINDINGPROC                    gl3wVertexArrayAttribBinding;
extern PFNGLVERTEXARRAYATTRIBFORMATPROC                     gl3wVertexArrayAttribFormat;
extern PFNGLVERTEXARRAYATTRIBIFORMATPROC                    gl3wVertexArrayAttribIFormat;
extern PFNGLVERTEXARRAYATTRIBLFORMATPROC                    gl3wVertexArrayAttribLFormat;
extern PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC              gl3wVertexArrayBindVertexBufferEXT;
extern PFNGLVERTEXARRAYBINDINGDIVISORPROC                   gl3wVertexArrayBindingDivisor;
extern PFNGLVERTEXARRAYCOLOROFFSETEXTPROC                   gl3wVertexArrayColorOffsetEXT;
extern PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC                gl3wVertexArrayEdgeFlagOffsetEXT;
extern PFNGLVERTEXARRAYELEMENTBUFFERPROC                    gl3wVertexArrayElementBuffer;
extern PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC                gl3wVertexArrayFogCoordOffsetEXT;
extern PFNGLVERTEXARRAYINDEXOFFSETEXTPROC                   gl3wVertexArrayIndexOffsetEXT;
extern PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC           gl3wVertexArrayMultiTexCoordOffsetEXT;
extern PFNGLVERTEXARRAYNORMALOFFSETEXTPROC                  gl3wVertexArrayNormalOffsetEXT;
extern PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC          gl3wVertexArraySecondaryColorOffsetEXT;
extern PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC                gl3wVertexArrayTexCoordOffsetEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC           gl3wVertexArrayVertexAttribBindingEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC           gl3wVertexArrayVertexAttribDivisorEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC            gl3wVertexArrayVertexAttribFormatEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC           gl3wVertexArrayVertexAttribIFormatEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC           gl3wVertexArrayVertexAttribIOffsetEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC           gl3wVertexArrayVertexAttribLFormatEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC           gl3wVertexArrayVertexAttribLOffsetEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC            gl3wVertexArrayVertexAttribOffsetEXT;
extern PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC          gl3wVertexArrayVertexBindingDivisorEXT;
extern PFNGLVERTEXARRAYVERTEXBUFFERPROC                     gl3wVertexArrayVertexBuffer;
extern PFNGLVERTEXARRAYVERTEXBUFFERSPROC                    gl3wVertexArrayVertexBuffers;
extern PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC                  gl3wVertexArrayVertexOffsetEXT;
extern PFNGLVERTEXATTRIB1DPROC                              gl3wVertexAttrib1d;
extern PFNGLVERTEXATTRIB1DVPROC                             gl3wVertexAttrib1dv;
extern PFNGLVERTEXATTRIB1FPROC                              gl3wVertexAttrib1f;
extern PFNGLVERTEXATTRIB1FVPROC                             gl3wVertexAttrib1fv;
extern PFNGLVERTEXATTRIB1SPROC                              gl3wVertexAttrib1s;
extern PFNGLVERTEXATTRIB1SVPROC                             gl3wVertexAttrib1sv;
extern PFNGLVERTEXATTRIB2DPROC                              gl3wVertexAttrib2d;
extern PFNGLVERTEXATTRIB2DVPROC                             gl3wVertexAttrib2dv;
extern PFNGLVERTEXATTRIB2FPROC                              gl3wVertexAttrib2f;
extern PFNGLVERTEXATTRIB2FVPROC                             gl3wVertexAttrib2fv;
extern PFNGLVERTEXATTRIB2SPROC                              gl3wVertexAttrib2s;
extern PFNGLVERTEXATTRIB2SVPROC                             gl3wVertexAttrib2sv;
extern PFNGLVERTEXATTRIB3DPROC                              gl3wVertexAttrib3d;
extern PFNGLVERTEXATTRIB3DVPROC                             gl3wVertexAttrib3dv;
extern PFNGLVERTEXATTRIB3FPROC                              gl3wVertexAttrib3f;
extern PFNGLVERTEXATTRIB3FVPROC                             gl3wVertexAttrib3fv;
extern PFNGLVERTEXATTRIB3SPROC                              gl3wVertexAttrib3s;
extern PFNGLVERTEXATTRIB3SVPROC                             gl3wVertexAttrib3sv;
extern PFNGLVERTEXATTRIB4NBVPROC                            gl3wVertexAttrib4Nbv;
extern PFNGLVERTEXATTRIB4NIVPROC                            gl3wVertexAttrib4Niv;
extern PFNGLVERTEXATTRIB4NSVPROC                            gl3wVertexAttrib4Nsv;
extern PFNGLVERTEXATTRIB4NUBPROC                            gl3wVertexAttrib4Nub;
extern PFNGLVERTEXATTRIB4NUBVPROC                           gl3wVertexAttrib4Nubv;
extern PFNGLVERTEXATTRIB4NUIVPROC                           gl3wVertexAttrib4Nuiv;
extern PFNGLVERTEXATTRIB4NUSVPROC                           gl3wVertexAttrib4Nusv;
extern PFNGLVERTEXATTRIB4BVPROC                             gl3wVertexAttrib4bv;
extern PFNGLVERTEXATTRIB4DPROC                              gl3wVertexAttrib4d;
extern PFNGLVERTEXATTRIB4DVPROC                             gl3wVertexAttrib4dv;
extern PFNGLVERTEXATTRIB4FPROC                              gl3wVertexAttrib4f;
extern PFNGLVERTEXATTRIB4FVPROC                             gl3wVertexAttrib4fv;
extern PFNGLVERTEXATTRIB4IVPROC                             gl3wVertexAttrib4iv;
extern PFNGLVERTEXATTRIB4SPROC                              gl3wVertexAttrib4s;
extern PFNGLVERTEXATTRIB4SVPROC                             gl3wVertexAttrib4sv;
extern PFNGLVERTEXATTRIB4UBVPROC                            gl3wVertexAttrib4ubv;
extern PFNGLVERTEXATTRIB4UIVPROC                            gl3wVertexAttrib4uiv;
extern PFNGLVERTEXATTRIB4USVPROC                            gl3wVertexAttrib4usv;
extern PFNGLVERTEXATTRIBBINDINGPROC                         gl3wVertexAttribBinding;
extern PFNGLVERTEXATTRIBDIVISORPROC                         gl3wVertexAttribDivisor;
extern PFNGLVERTEXATTRIBDIVISORARBPROC                      gl3wVertexAttribDivisorARB;
extern PFNGLVERTEXATTRIBFORMATPROC                          gl3wVertexAttribFormat;
extern PFNGLVERTEXATTRIBFORMATNVPROC                        gl3wVertexAttribFormatNV;
extern PFNGLVERTEXATTRIBI1IPROC                             gl3wVertexAttribI1i;
extern PFNGLVERTEXATTRIBI1IVPROC                            gl3wVertexAttribI1iv;
extern PFNGLVERTEXATTRIBI1UIPROC                            gl3wVertexAttribI1ui;
extern PFNGLVERTEXATTRIBI1UIVPROC                           gl3wVertexAttribI1uiv;
extern PFNGLVERTEXATTRIBI2IPROC                             gl3wVertexAttribI2i;
extern PFNGLVERTEXATTRIBI2IVPROC                            gl3wVertexAttribI2iv;
extern PFNGLVERTEXATTRIBI2UIPROC                            gl3wVertexAttribI2ui;
extern PFNGLVERTEXATTRIBI2UIVPROC                           gl3wVertexAttribI2uiv;
extern PFNGLVERTEXATTRIBI3IPROC                             gl3wVertexAttribI3i;
extern PFNGLVERTEXATTRIBI3IVPROC                            gl3wVertexAttribI3iv;
extern PFNGLVERTEXATTRIBI3UIPROC                            gl3wVertexAttribI3ui;
extern PFNGLVERTEXATTRIBI3UIVPROC                           gl3wVertexAttribI3uiv;
extern PFNGLVERTEXATTRIBI4BVPROC                            gl3wVertexAttribI4bv;
extern PFNGLVERTEXATTRIBI4IPROC                             gl3wVertexAttribI4i;
extern PFNGLVERTEXATTRIBI4IVPROC                            gl3wVertexAttribI4iv;
extern PFNGLVERTEXATTRIBI4SVPROC                            gl3wVertexAttribI4sv;
extern PFNGLVERTEXATTRIBI4UBVPROC                           gl3wVertexAttribI4ubv;
extern PFNGLVERTEXATTRIBI4UIPROC                            gl3wVertexAttribI4ui;
extern PFNGLVERTEXATTRIBI4UIVPROC                           gl3wVertexAttribI4uiv;
extern PFNGLVERTEXATTRIBI4USVPROC                           gl3wVertexAttribI4usv;
extern PFNGLVERTEXATTRIBIFORMATPROC                         gl3wVertexAttribIFormat;
extern PFNGLVERTEXATTRIBIFORMATNVPROC                       gl3wVertexAttribIFormatNV;
extern PFNGLVERTEXATTRIBIPOINTERPROC                        gl3wVertexAttribIPointer;
extern PFNGLVERTEXATTRIBL1DPROC                             gl3wVertexAttribL1d;
extern PFNGLVERTEXATTRIBL1DVPROC                            gl3wVertexAttribL1dv;
extern PFNGLVERTEXATTRIBL1I64NVPROC                         gl3wVertexAttribL1i64NV;
extern PFNGLVERTEXATTRIBL1I64VNVPROC                        gl3wVertexAttribL1i64vNV;
extern PFNGLVERTEXATTRIBL1UI64ARBPROC                       gl3wVertexAttribL1ui64ARB;
extern PFNGLVERTEXATTRIBL1UI64NVPROC                        gl3wVertexAttribL1ui64NV;
extern PFNGLVERTEXATTRIBL1UI64VARBPROC                      gl3wVertexAttribL1ui64vARB;
extern PFNGLVERTEXATTRIBL1UI64VNVPROC                       gl3wVertexAttribL1ui64vNV;
extern PFNGLVERTEXATTRIBL2DPROC                             gl3wVertexAttribL2d;
extern PFNGLVERTEXATTRIBL2DVPROC                            gl3wVertexAttribL2dv;
extern PFNGLVERTEXATTRIBL2I64NVPROC                         gl3wVertexAttribL2i64NV;
extern PFNGLVERTEXATTRIBL2I64VNVPROC                        gl3wVertexAttribL2i64vNV;
extern PFNGLVERTEXATTRIBL2UI64NVPROC                        gl3wVertexAttribL2ui64NV;
extern PFNGLVERTEXATTRIBL2UI64VNVPROC                       gl3wVertexAttribL2ui64vNV;
extern PFNGLVERTEXATTRIBL3DPROC                             gl3wVertexAttribL3d;
extern PFNGLVERTEXATTRIBL3DVPROC                            gl3wVertexAttribL3dv;
extern PFNGLVERTEXATTRIBL3I64NVPROC                         gl3wVertexAttribL3i64NV;
extern PFNGLVERTEXATTRIBL3I64VNVPROC                        gl3wVertexAttribL3i64vNV;
extern PFNGLVERTEXATTRIBL3UI64NVPROC                        gl3wVertexAttribL3ui64NV;
extern PFNGLVERTEXATTRIBL3UI64VNVPROC                       gl3wVertexAttribL3ui64vNV;
extern PFNGLVERTEXATTRIBL4DPROC                             gl3wVertexAttribL4d;
extern PFNGLVERTEXATTRIBL4DVPROC                            gl3wVertexAttribL4dv;
extern PFNGLVERTEXATTRIBL4I64NVPROC                         gl3wVertexAttribL4i64NV;
extern PFNGLVERTEXATTRIBL4I64VNVPROC                        gl3wVertexAttribL4i64vNV;
extern PFNGLVERTEXATTRIBL4UI64NVPROC                        gl3wVertexAttribL4ui64NV;
extern PFNGLVERTEXATTRIBL4UI64VNVPROC                       gl3wVertexAttribL4ui64vNV;
extern PFNGLVERTEXATTRIBLFORMATPROC                         gl3wVertexAttribLFormat;
extern PFNGLVERTEXATTRIBLFORMATNVPROC                       gl3wVertexAttribLFormatNV;
extern PFNGLVERTEXATTRIBLPOINTERPROC                        gl3wVertexAttribLPointer;
extern PFNGLVERTEXATTRIBP1UIPROC                            gl3wVertexAttribP1ui;
extern PFNGLVERTEXATTRIBP1UIVPROC                           gl3wVertexAttribP1uiv;
extern PFNGLVERTEXATTRIBP2UIPROC                            gl3wVertexAttribP2ui;
extern PFNGLVERTEXATTRIBP2UIVPROC                           gl3wVertexAttribP2uiv;
extern PFNGLVERTEXATTRIBP3UIPROC                            gl3wVertexAttribP3ui;
extern PFNGLVERTEXATTRIBP3UIVPROC                           gl3wVertexAttribP3uiv;
extern PFNGLVERTEXATTRIBP4UIPROC                            gl3wVertexAttribP4ui;
extern PFNGLVERTEXATTRIBP4UIVPROC                           gl3wVertexAttribP4uiv;
extern PFNGLVERTEXATTRIBPOINTERPROC                         gl3wVertexAttribPointer;
extern PFNGLVERTEXBINDINGDIVISORPROC                        gl3wVertexBindingDivisor;
extern PFNGLVERTEXFORMATNVPROC                              gl3wVertexFormatNV;
extern PFNGLVIEWPORTPROC                                    gl3wViewport;
extern PFNGLVIEWPORTARRAYVPROC                              gl3wViewportArrayv;
extern PFNGLVIEWPORTINDEXEDFPROC                            gl3wViewportIndexedf;
extern PFNGLVIEWPORTINDEXEDFVPROC                           gl3wViewportIndexedfv;
extern PFNGLVIEWPORTPOSITIONWSCALENVPROC                    gl3wViewportPositionWScaleNV;
extern PFNGLVIEWPORTSWIZZLENVPROC                           gl3wViewportSwizzleNV;
extern PFNGLWAITSYNCPROC                                    gl3wWaitSync;
extern PFNGLWAITVKSEMAPHORENVPROC                           gl3wWaitVkSemaphoreNV;
extern PFNGLWEIGHTPATHSNVPROC                               gl3wWeightPathsNV;
extern PFNGLWINDOWRECTANGLESEXTPROC                         gl3wWindowRectanglesEXT;

#define glActiveProgramEXT                            gl3wActiveProgramEXT
#define glActiveShaderProgram                         gl3wActiveShaderProgram
#define glActiveTexture                               gl3wActiveTexture
#define glApplyFramebufferAttachmentCMAAINTEL         gl3wApplyFramebufferAttachmentCMAAINTEL
#define glAttachShader                                gl3wAttachShader
#define glBeginConditionalRender                      gl3wBeginConditionalRender
#define glBeginConditionalRenderNV                    gl3wBeginConditionalRenderNV
#define glBeginPerfMonitorAMD                         gl3wBeginPerfMonitorAMD
#define glBeginPerfQueryINTEL                         gl3wBeginPerfQueryINTEL
#define glBeginQuery                                  gl3wBeginQuery
#define glBeginQueryIndexed                           gl3wBeginQueryIndexed
#define glBeginTransformFeedback                      gl3wBeginTransformFeedback
#define glBindAttribLocation                          gl3wBindAttribLocation
#define glBindBuffer                                  gl3wBindBuffer
#define glBindBufferBase                              gl3wBindBufferBase
#define glBindBufferRange                             gl3wBindBufferRange
#define glBindBuffersBase                             gl3wBindBuffersBase
#define glBindBuffersRange                            gl3wBindBuffersRange
#define glBindFragDataLocation                        gl3wBindFragDataLocation
#define glBindFragDataLocationIndexed                 gl3wBindFragDataLocationIndexed
#define glBindFramebuffer                             gl3wBindFramebuffer
#define glBindImageTexture                            gl3wBindImageTexture
#define glBindImageTextures                           gl3wBindImageTextures
#define glBindMultiTextureEXT                         gl3wBindMultiTextureEXT
#define glBindProgramPipeline                         gl3wBindProgramPipeline
#define glBindRenderbuffer                            gl3wBindRenderbuffer
#define glBindSampler                                 gl3wBindSampler
#define glBindSamplers                                gl3wBindSamplers
#define glBindTexture                                 gl3wBindTexture
#define glBindTextureUnit                             gl3wBindTextureUnit
#define glBindTextures                                gl3wBindTextures
#define glBindTransformFeedback                       gl3wBindTransformFeedback
#define glBindVertexArray                             gl3wBindVertexArray
#define glBindVertexBuffer                            gl3wBindVertexBuffer
#define glBindVertexBuffers                           gl3wBindVertexBuffers
#define glBlendBarrierKHR                             gl3wBlendBarrierKHR
#define glBlendBarrierNV                              gl3wBlendBarrierNV
#define glBlendColor                                  gl3wBlendColor
#define glBlendEquation                               gl3wBlendEquation
#define glBlendEquationSeparate                       gl3wBlendEquationSeparate
#define glBlendEquationSeparatei                      gl3wBlendEquationSeparatei
#define glBlendEquationSeparateiARB                   gl3wBlendEquationSeparateiARB
#define glBlendEquationi                              gl3wBlendEquationi
#define glBlendEquationiARB                           gl3wBlendEquationiARB
#define glBlendFunc                                   gl3wBlendFunc
#define glBlendFuncSeparate                           gl3wBlendFuncSeparate
#define glBlendFuncSeparatei                          gl3wBlendFuncSeparatei
#define glBlendFuncSeparateiARB                       gl3wBlendFuncSeparateiARB
#define glBlendFunci                                  gl3wBlendFunci
#define glBlendFunciARB                               gl3wBlendFunciARB
#define glBlendParameteriNV                           gl3wBlendParameteriNV
#define glBlitFramebuffer                             gl3wBlitFramebuffer
#define glBlitNamedFramebuffer                        gl3wBlitNamedFramebuffer
#define glBufferAddressRangeNV                        gl3wBufferAddressRangeNV
#define glBufferData                                  gl3wBufferData
#define glBufferPageCommitmentARB                     gl3wBufferPageCommitmentARB
#define glBufferStorage                               gl3wBufferStorage
#define glBufferSubData                               gl3wBufferSubData
#define glCallCommandListNV                           gl3wCallCommandListNV
#define glCheckFramebufferStatus                      gl3wCheckFramebufferStatus
#define glCheckNamedFramebufferStatus                 gl3wCheckNamedFramebufferStatus
#define glCheckNamedFramebufferStatusEXT              gl3wCheckNamedFramebufferStatusEXT
#define glClampColor                                  gl3wClampColor
#define glClear                                       gl3wClear
#define glClearBufferData                             gl3wClearBufferData
#define glClearBufferSubData                          gl3wClearBufferSubData
#define glClearBufferfi                               gl3wClearBufferfi
#define glClearBufferfv                               gl3wClearBufferfv
#define glClearBufferiv                               gl3wClearBufferiv
#define glClearBufferuiv                              gl3wClearBufferuiv
#define glClearColor                                  gl3wClearColor
#define glClearDepth                                  gl3wClearDepth
#define glClearDepthf                                 gl3wClearDepthf
#define glClearNamedBufferData                        gl3wClearNamedBufferData
#define glClearNamedBufferDataEXT                     gl3wClearNamedBufferDataEXT
#define glClearNamedBufferSubData                     gl3wClearNamedBufferSubData
#define glClearNamedBufferSubDataEXT                  gl3wClearNamedBufferSubDataEXT
#define glClearNamedFramebufferfi                     gl3wClearNamedFramebufferfi
#define glClearNamedFramebufferfv                     gl3wClearNamedFramebufferfv
#define glClearNamedFramebufferiv                     gl3wClearNamedFramebufferiv
#define glClearNamedFramebufferuiv                    gl3wClearNamedFramebufferuiv
#define glClearStencil                                gl3wClearStencil
#define glClearTexImage                               gl3wClearTexImage
#define glClearTexSubImage                            gl3wClearTexSubImage
#define glClientAttribDefaultEXT                      gl3wClientAttribDefaultEXT
#define glClientWaitSync                              gl3wClientWaitSync
#define glClipControl                                 gl3wClipControl
#define glColorFormatNV                               gl3wColorFormatNV
#define glColorMask                                   gl3wColorMask
#define glColorMaski                                  gl3wColorMaski
#define glCommandListSegmentsNV                       gl3wCommandListSegmentsNV
#define glCompileCommandListNV                        gl3wCompileCommandListNV
#define glCompileShader                               gl3wCompileShader
#define glCompileShaderIncludeARB                     gl3wCompileShaderIncludeARB
#define glCompressedMultiTexImage1DEXT                gl3wCompressedMultiTexImage1DEXT
#define glCompressedMultiTexImage2DEXT                gl3wCompressedMultiTexImage2DEXT
#define glCompressedMultiTexImage3DEXT                gl3wCompressedMultiTexImage3DEXT
#define glCompressedMultiTexSubImage1DEXT             gl3wCompressedMultiTexSubImage1DEXT
#define glCompressedMultiTexSubImage2DEXT             gl3wCompressedMultiTexSubImage2DEXT
#define glCompressedMultiTexSubImage3DEXT             gl3wCompressedMultiTexSubImage3DEXT
#define glCompressedTexImage1D                        gl3wCompressedTexImage1D
#define glCompressedTexImage2D                        gl3wCompressedTexImage2D
#define glCompressedTexImage3D                        gl3wCompressedTexImage3D
#define glCompressedTexSubImage1D                     gl3wCompressedTexSubImage1D
#define glCompressedTexSubImage2D                     gl3wCompressedTexSubImage2D
#define glCompressedTexSubImage3D                     gl3wCompressedTexSubImage3D
#define glCompressedTextureImage1DEXT                 gl3wCompressedTextureImage1DEXT
#define glCompressedTextureImage2DEXT                 gl3wCompressedTextureImage2DEXT
#define glCompressedTextureImage3DEXT                 gl3wCompressedTextureImage3DEXT
#define glCompressedTextureSubImage1D                 gl3wCompressedTextureSubImage1D
#define glCompressedTextureSubImage1DEXT              gl3wCompressedTextureSubImage1DEXT
#define glCompressedTextureSubImage2D                 gl3wCompressedTextureSubImage2D
#define glCompressedTextureSubImage2DEXT              gl3wCompressedTextureSubImage2DEXT
#define glCompressedTextureSubImage3D                 gl3wCompressedTextureSubImage3D
#define glCompressedTextureSubImage3DEXT              gl3wCompressedTextureSubImage3DEXT
#define glConservativeRasterParameterfNV              gl3wConservativeRasterParameterfNV
#define glConservativeRasterParameteriNV              gl3wConservativeRasterParameteriNV
#define glCopyBufferSubData                           gl3wCopyBufferSubData
#define glCopyImageSubData                            gl3wCopyImageSubData
#define glCopyMultiTexImage1DEXT                      gl3wCopyMultiTexImage1DEXT
#define glCopyMultiTexImage2DEXT                      gl3wCopyMultiTexImage2DEXT
#define glCopyMultiTexSubImage1DEXT                   gl3wCopyMultiTexSubImage1DEXT
#define glCopyMultiTexSubImage2DEXT                   gl3wCopyMultiTexSubImage2DEXT
#define glCopyMultiTexSubImage3DEXT                   gl3wCopyMultiTexSubImage3DEXT
#define glCopyNamedBufferSubData                      gl3wCopyNamedBufferSubData
#define glCopyPathNV                                  gl3wCopyPathNV
#define glCopyTexImage1D                              gl3wCopyTexImage1D
#define glCopyTexImage2D                              gl3wCopyTexImage2D
#define glCopyTexSubImage1D                           gl3wCopyTexSubImage1D
#define glCopyTexSubImage2D                           gl3wCopyTexSubImage2D
#define glCopyTexSubImage3D                           gl3wCopyTexSubImage3D
#define glCopyTextureImage1DEXT                       gl3wCopyTextureImage1DEXT
#define glCopyTextureImage2DEXT                       gl3wCopyTextureImage2DEXT
#define glCopyTextureSubImage1D                       gl3wCopyTextureSubImage1D
#define glCopyTextureSubImage1DEXT                    gl3wCopyTextureSubImage1DEXT
#define glCopyTextureSubImage2D                       gl3wCopyTextureSubImage2D
#define glCopyTextureSubImage2DEXT                    gl3wCopyTextureSubImage2DEXT
#define glCopyTextureSubImage3D                       gl3wCopyTextureSubImage3D
#define glCopyTextureSubImage3DEXT                    gl3wCopyTextureSubImage3DEXT
#define glCoverFillPathInstancedNV                    gl3wCoverFillPathInstancedNV
#define glCoverFillPathNV                             gl3wCoverFillPathNV
#define glCoverStrokePathInstancedNV                  gl3wCoverStrokePathInstancedNV
#define glCoverStrokePathNV                           gl3wCoverStrokePathNV
#define glCoverageModulationNV                        gl3wCoverageModulationNV
#define glCoverageModulationTableNV                   gl3wCoverageModulationTableNV
#define glCreateBuffers                               gl3wCreateBuffers
#define glCreateCommandListsNV                        gl3wCreateCommandListsNV
#define glCreateFramebuffers                          gl3wCreateFramebuffers
#define glCreatePerfQueryINTEL                        gl3wCreatePerfQueryINTEL
#define glCreateProgram                               gl3wCreateProgram
#define glCreateProgramPipelines                      gl3wCreateProgramPipelines
#define glCreateQueries                               gl3wCreateQueries
#define glCreateRenderbuffers                         gl3wCreateRenderbuffers
#define glCreateSamplers                              gl3wCreateSamplers
#define glCreateShader                                gl3wCreateShader
#define glCreateShaderProgramEXT                      gl3wCreateShaderProgramEXT
#define glCreateShaderProgramv                        gl3wCreateShaderProgramv
#define glCreateStatesNV                              gl3wCreateStatesNV
#define glCreateSyncFromCLeventARB                    gl3wCreateSyncFromCLeventARB
#define glCreateTextures                              gl3wCreateTextures
#define glCreateTransformFeedbacks                    gl3wCreateTransformFeedbacks
#define glCreateVertexArrays                          gl3wCreateVertexArrays
#define glCullFace                                    gl3wCullFace
#define glDebugMessageCallback                        gl3wDebugMessageCallback
#define glDebugMessageCallbackARB                     gl3wDebugMessageCallbackARB
#define glDebugMessageControl                         gl3wDebugMessageControl
#define glDebugMessageControlARB                      gl3wDebugMessageControlARB
#define glDebugMessageInsert                          gl3wDebugMessageInsert
#define glDebugMessageInsertARB                       gl3wDebugMessageInsertARB
#define glDeleteBuffers                               gl3wDeleteBuffers
#define glDeleteCommandListsNV                        gl3wDeleteCommandListsNV
#define glDeleteFramebuffers                          gl3wDeleteFramebuffers
#define glDeleteNamedStringARB                        gl3wDeleteNamedStringARB
#define glDeletePathsNV                               gl3wDeletePathsNV
#define glDeletePerfMonitorsAMD                       gl3wDeletePerfMonitorsAMD
#define glDeletePerfQueryINTEL                        gl3wDeletePerfQueryINTEL
#define glDeleteProgram                               gl3wDeleteProgram
#define glDeleteProgramPipelines                      gl3wDeleteProgramPipelines
#define glDeleteQueries                               gl3wDeleteQueries
#define glDeleteRenderbuffers                         gl3wDeleteRenderbuffers
#define glDeleteSamplers                              gl3wDeleteSamplers
#define glDeleteShader                                gl3wDeleteShader
#define glDeleteStatesNV                              gl3wDeleteStatesNV
#define glDeleteSync                                  gl3wDeleteSync
#define glDeleteTextures                              gl3wDeleteTextures
#define glDeleteTransformFeedbacks                    gl3wDeleteTransformFeedbacks
#define glDeleteVertexArrays                          gl3wDeleteVertexArrays
#define glDepthFunc                                   gl3wDepthFunc
#define glDepthMask                                   gl3wDepthMask
#define glDepthRange                                  gl3wDepthRange
#define glDepthRangeArrayv                            gl3wDepthRangeArrayv
#define glDepthRangeIndexed                           gl3wDepthRangeIndexed
#define glDepthRangef                                 gl3wDepthRangef
#define glDetachShader                                gl3wDetachShader
#define glDisable                                     gl3wDisable
#define glDisableClientStateIndexedEXT                gl3wDisableClientStateIndexedEXT
#define glDisableClientStateiEXT                      gl3wDisableClientStateiEXT
#define glDisableIndexedEXT                           gl3wDisableIndexedEXT
#define glDisableVertexArrayAttrib                    gl3wDisableVertexArrayAttrib
#define glDisableVertexArrayAttribEXT                 gl3wDisableVertexArrayAttribEXT
#define glDisableVertexArrayEXT                       gl3wDisableVertexArrayEXT
#define glDisableVertexAttribArray                    gl3wDisableVertexAttribArray
#define glDisablei                                    gl3wDisablei
#define glDispatchCompute                             gl3wDispatchCompute
#define glDispatchComputeGroupSizeARB                 gl3wDispatchComputeGroupSizeARB
#define glDispatchComputeIndirect                     gl3wDispatchComputeIndirect
#define glDrawArrays                                  gl3wDrawArrays
#define glDrawArraysIndirect                          gl3wDrawArraysIndirect
#define glDrawArraysInstanced                         gl3wDrawArraysInstanced
#define glDrawArraysInstancedARB                      gl3wDrawArraysInstancedARB
#define glDrawArraysInstancedBaseInstance             gl3wDrawArraysInstancedBaseInstance
#define glDrawArraysInstancedEXT                      gl3wDrawArraysInstancedEXT
#define glDrawBuffer                                  gl3wDrawBuffer
#define glDrawBuffers                                 gl3wDrawBuffers
#define glDrawCommandsAddressNV                       gl3wDrawCommandsAddressNV
#define glDrawCommandsNV                              gl3wDrawCommandsNV
#define glDrawCommandsStatesAddressNV                 gl3wDrawCommandsStatesAddressNV
#define glDrawCommandsStatesNV                        gl3wDrawCommandsStatesNV
#define glDrawElements                                gl3wDrawElements
#define glDrawElementsBaseVertex                      gl3wDrawElementsBaseVertex
#define glDrawElementsIndirect                        gl3wDrawElementsIndirect
#define glDrawElementsInstanced                       gl3wDrawElementsInstanced
#define glDrawElementsInstancedARB                    gl3wDrawElementsInstancedARB
#define glDrawElementsInstancedBaseInstance           gl3wDrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertex             gl3wDrawElementsInstancedBaseVertex
#define glDrawElementsInstancedBaseVertexBaseInstance gl3wDrawElementsInstancedBaseVertexBaseInstance
#define glDrawElementsInstancedEXT                    gl3wDrawElementsInstancedEXT
#define glDrawRangeElements                           gl3wDrawRangeElements
#define glDrawRangeElementsBaseVertex                 gl3wDrawRangeElementsBaseVertex
#define glDrawTransformFeedback                       gl3wDrawTransformFeedback
#define glDrawTransformFeedbackInstanced              gl3wDrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStream                 gl3wDrawTransformFeedbackStream
#define glDrawTransformFeedbackStreamInstanced        gl3wDrawTransformFeedbackStreamInstanced
#define glDrawVkImageNV                               gl3wDrawVkImageNV
#define glEdgeFlagFormatNV                            gl3wEdgeFlagFormatNV
#define glEnable                                      gl3wEnable
#define glEnableClientStateIndexedEXT                 gl3wEnableClientStateIndexedEXT
#define glEnableClientStateiEXT                       gl3wEnableClientStateiEXT
#define glEnableIndexedEXT                            gl3wEnableIndexedEXT
#define glEnableVertexArrayAttrib                     gl3wEnableVertexArrayAttrib
#define glEnableVertexArrayAttribEXT                  gl3wEnableVertexArrayAttribEXT
#define glEnableVertexArrayEXT                        gl3wEnableVertexArrayEXT
#define glEnableVertexAttribArray                     gl3wEnableVertexAttribArray
#define glEnablei                                     gl3wEnablei
#define glEndConditionalRender                        gl3wEndConditionalRender
#define glEndConditionalRenderNV                      gl3wEndConditionalRenderNV
#define glEndPerfMonitorAMD                           gl3wEndPerfMonitorAMD
#define glEndPerfQueryINTEL                           gl3wEndPerfQueryINTEL
#define glEndQuery                                    gl3wEndQuery
#define glEndQueryIndexed                             gl3wEndQueryIndexed
#define glEndTransformFeedback                        gl3wEndTransformFeedback
#define glEvaluateDepthValuesARB                      gl3wEvaluateDepthValuesARB
#define glFenceSync                                   gl3wFenceSync
#define glFinish                                      gl3wFinish
#define glFlush                                       gl3wFlush
#define glFlushMappedBufferRange                      gl3wFlushMappedBufferRange
#define glFlushMappedNamedBufferRange                 gl3wFlushMappedNamedBufferRange
#define glFlushMappedNamedBufferRangeEXT              gl3wFlushMappedNamedBufferRangeEXT
#define glFogCoordFormatNV                            gl3wFogCoordFormatNV
#define glFragmentCoverageColorNV                     gl3wFragmentCoverageColorNV
#define glFramebufferDrawBufferEXT                    gl3wFramebufferDrawBufferEXT
#define glFramebufferDrawBuffersEXT                   gl3wFramebufferDrawBuffersEXT
#define glFramebufferParameteri                       gl3wFramebufferParameteri
#define glFramebufferReadBufferEXT                    gl3wFramebufferReadBufferEXT
#define glFramebufferRenderbuffer                     gl3wFramebufferRenderbuffer
#define glFramebufferSampleLocationsfvARB             gl3wFramebufferSampleLocationsfvARB
#define glFramebufferSampleLocationsfvNV              gl3wFramebufferSampleLocationsfvNV
#define glFramebufferTexture                          gl3wFramebufferTexture
#define glFramebufferTexture1D                        gl3wFramebufferTexture1D
#define glFramebufferTexture2D                        gl3wFramebufferTexture2D
#define glFramebufferTexture3D                        gl3wFramebufferTexture3D
#define glFramebufferTextureARB                       gl3wFramebufferTextureARB
#define glFramebufferTextureFaceARB                   gl3wFramebufferTextureFaceARB
#define glFramebufferTextureLayer                     gl3wFramebufferTextureLayer
#define glFramebufferTextureLayerARB                  gl3wFramebufferTextureLayerARB
#define glFramebufferTextureMultiviewOVR              gl3wFramebufferTextureMultiviewOVR
#define glFrontFace                                   gl3wFrontFace
#define glGenBuffers                                  gl3wGenBuffers
#define glGenFramebuffers                             gl3wGenFramebuffers
#define glGenPathsNV                                  gl3wGenPathsNV
#define glGenPerfMonitorsAMD                          gl3wGenPerfMonitorsAMD
#define glGenProgramPipelines                         gl3wGenProgramPipelines
#define glGenQueries                                  gl3wGenQueries
#define glGenRenderbuffers                            gl3wGenRenderbuffers
#define glGenSamplers                                 gl3wGenSamplers
#define glGenTextures                                 gl3wGenTextures
#define glGenTransformFeedbacks                       gl3wGenTransformFeedbacks
#define glGenVertexArrays                             gl3wGenVertexArrays
#define glGenerateMipmap                              gl3wGenerateMipmap
#define glGenerateMultiTexMipmapEXT                   gl3wGenerateMultiTexMipmapEXT
#define glGenerateTextureMipmap                       gl3wGenerateTextureMipmap
#define glGenerateTextureMipmapEXT                    gl3wGenerateTextureMipmapEXT
#define glGetActiveAtomicCounterBufferiv              gl3wGetActiveAtomicCounterBufferiv
#define glGetActiveAttrib                             gl3wGetActiveAttrib
#define glGetActiveSubroutineName                     gl3wGetActiveSubroutineName
#define glGetActiveSubroutineUniformName              gl3wGetActiveSubroutineUniformName
#define glGetActiveSubroutineUniformiv                gl3wGetActiveSubroutineUniformiv
#define glGetActiveUniform                            gl3wGetActiveUniform
#define glGetActiveUniformBlockName                   gl3wGetActiveUniformBlockName
#define glGetActiveUniformBlockiv                     gl3wGetActiveUniformBlockiv
#define glGetActiveUniformName                        gl3wGetActiveUniformName
#define glGetActiveUniformsiv                         gl3wGetActiveUniformsiv
#define glGetAttachedShaders                          gl3wGetAttachedShaders
#define glGetAttribLocation                           gl3wGetAttribLocation
#define glGetBooleanIndexedvEXT                       gl3wGetBooleanIndexedvEXT
#define glGetBooleani_v                               gl3wGetBooleani_v
#define glGetBooleanv                                 gl3wGetBooleanv
#define glGetBufferParameteri64v                      gl3wGetBufferParameteri64v
#define glGetBufferParameteriv                        gl3wGetBufferParameteriv
#define glGetBufferParameterui64vNV                   gl3wGetBufferParameterui64vNV
#define glGetBufferPointerv                           gl3wGetBufferPointerv
#define glGetBufferSubData                            gl3wGetBufferSubData
#define glGetCommandHeaderNV                          gl3wGetCommandHeaderNV
#define glGetCompressedMultiTexImageEXT               gl3wGetCompressedMultiTexImageEXT
#define glGetCompressedTexImage                       gl3wGetCompressedTexImage
#define glGetCompressedTextureImage                   gl3wGetCompressedTextureImage
#define glGetCompressedTextureImageEXT                gl3wGetCompressedTextureImageEXT
#define glGetCompressedTextureSubImage                gl3wGetCompressedTextureSubImage
#define glGetCoverageModulationTableNV                gl3wGetCoverageModulationTableNV
#define glGetDebugMessageLog                          gl3wGetDebugMessageLog
#define glGetDebugMessageLogARB                       gl3wGetDebugMessageLogARB
#define glGetDoubleIndexedvEXT                        gl3wGetDoubleIndexedvEXT
#define glGetDoublei_v                                gl3wGetDoublei_v
#define glGetDoublei_vEXT                             gl3wGetDoublei_vEXT
#define glGetDoublev                                  gl3wGetDoublev
#define glGetError                                    gl3wGetError
#define glGetFirstPerfQueryIdINTEL                    gl3wGetFirstPerfQueryIdINTEL
#define glGetFloatIndexedvEXT                         gl3wGetFloatIndexedvEXT
#define glGetFloati_v                                 gl3wGetFloati_v
#define glGetFloati_vEXT                              gl3wGetFloati_vEXT
#define glGetFloatv                                   gl3wGetFloatv
#define glGetFragDataIndex                            gl3wGetFragDataIndex
#define glGetFragDataLocation                         gl3wGetFragDataLocation
#define glGetFramebufferAttachmentParameteriv         gl3wGetFramebufferAttachmentParameteriv
#define glGetFramebufferParameteriv                   gl3wGetFramebufferParameteriv
#define glGetFramebufferParameterivEXT                gl3wGetFramebufferParameterivEXT
#define glGetGraphicsResetStatus                      gl3wGetGraphicsResetStatus
#define glGetGraphicsResetStatusARB                   gl3wGetGraphicsResetStatusARB
#define glGetImageHandleARB                           gl3wGetImageHandleARB
#define glGetImageHandleNV                            gl3wGetImageHandleNV
#define glGetInteger64i_v                             gl3wGetInteger64i_v
#define glGetInteger64v                               gl3wGetInteger64v
#define glGetIntegerIndexedvEXT                       gl3wGetIntegerIndexedvEXT
#define glGetIntegeri_v                               gl3wGetIntegeri_v
#define glGetIntegerui64i_vNV                         gl3wGetIntegerui64i_vNV
#define glGetIntegerui64vNV                           gl3wGetIntegerui64vNV
#define glGetIntegerv                                 gl3wGetIntegerv
#define glGetInternalformatSampleivNV                 gl3wGetInternalformatSampleivNV
#define glGetInternalformati64v                       gl3wGetInternalformati64v
#define glGetInternalformativ                         gl3wGetInternalformativ
#define glGetMultiTexEnvfvEXT                         gl3wGetMultiTexEnvfvEXT
#define glGetMultiTexEnvivEXT                         gl3wGetMultiTexEnvivEXT
#define glGetMultiTexGendvEXT                         gl3wGetMultiTexGendvEXT
#define glGetMultiTexGenfvEXT                         gl3wGetMultiTexGenfvEXT
#define glGetMultiTexGenivEXT                         gl3wGetMultiTexGenivEXT
#define glGetMultiTexImageEXT                         gl3wGetMultiTexImageEXT
#define glGetMultiTexLevelParameterfvEXT              gl3wGetMultiTexLevelParameterfvEXT
#define glGetMultiTexLevelParameterivEXT              gl3wGetMultiTexLevelParameterivEXT
#define glGetMultiTexParameterIivEXT                  gl3wGetMultiTexParameterIivEXT
#define glGetMultiTexParameterIuivEXT                 gl3wGetMultiTexParameterIuivEXT
#define glGetMultiTexParameterfvEXT                   gl3wGetMultiTexParameterfvEXT
#define glGetMultiTexParameterivEXT                   gl3wGetMultiTexParameterivEXT
#define glGetMultisamplefv                            gl3wGetMultisamplefv
#define glGetNamedBufferParameteri64v                 gl3wGetNamedBufferParameteri64v
#define glGetNamedBufferParameteriv                   gl3wGetNamedBufferParameteriv
#define glGetNamedBufferParameterivEXT                gl3wGetNamedBufferParameterivEXT
#define glGetNamedBufferParameterui64vNV              gl3wGetNamedBufferParameterui64vNV
#define glGetNamedBufferPointerv                      gl3wGetNamedBufferPointerv
#define glGetNamedBufferPointervEXT                   gl3wGetNamedBufferPointervEXT
#define glGetNamedBufferSubData                       gl3wGetNamedBufferSubData
#define glGetNamedBufferSubDataEXT                    gl3wGetNamedBufferSubDataEXT
#define glGetNamedFramebufferAttachmentParameteriv    gl3wGetNamedFramebufferAttachmentParameteriv
#define glGetNamedFramebufferAttachmentParameterivEXT gl3wGetNamedFramebufferAttachmentParameterivEXT
#define glGetNamedFramebufferParameteriv              gl3wGetNamedFramebufferParameteriv
#define glGetNamedFramebufferParameterivEXT           gl3wGetNamedFramebufferParameterivEXT
#define glGetNamedProgramLocalParameterIivEXT         gl3wGetNamedProgramLocalParameterIivEXT
#define glGetNamedProgramLocalParameterIuivEXT        gl3wGetNamedProgramLocalParameterIuivEXT
#define glGetNamedProgramLocalParameterdvEXT          gl3wGetNamedProgramLocalParameterdvEXT
#define glGetNamedProgramLocalParameterfvEXT          gl3wGetNamedProgramLocalParameterfvEXT
#define glGetNamedProgramStringEXT                    gl3wGetNamedProgramStringEXT
#define glGetNamedProgramivEXT                        gl3wGetNamedProgramivEXT
#define glGetNamedRenderbufferParameteriv             gl3wGetNamedRenderbufferParameteriv
#define glGetNamedRenderbufferParameterivEXT          gl3wGetNamedRenderbufferParameterivEXT
#define glGetNamedStringARB                           gl3wGetNamedStringARB
#define glGetNamedStringivARB                         gl3wGetNamedStringivARB
#define glGetNextPerfQueryIdINTEL                     gl3wGetNextPerfQueryIdINTEL
#define glGetObjectLabel                              gl3wGetObjectLabel
#define glGetObjectLabelEXT                           gl3wGetObjectLabelEXT
#define glGetObjectPtrLabel                           gl3wGetObjectPtrLabel
#define glGetPathCommandsNV                           gl3wGetPathCommandsNV
#define glGetPathCoordsNV                             gl3wGetPathCoordsNV
#define glGetPathDashArrayNV                          gl3wGetPathDashArrayNV
#define glGetPathLengthNV                             gl3wGetPathLengthNV
#define glGetPathMetricRangeNV                        gl3wGetPathMetricRangeNV
#define glGetPathMetricsNV                            gl3wGetPathMetricsNV
#define glGetPathParameterfvNV                        gl3wGetPathParameterfvNV
#define glGetPathParameterivNV                        gl3wGetPathParameterivNV
#define glGetPathSpacingNV                            gl3wGetPathSpacingNV
#define glGetPerfCounterInfoINTEL                     gl3wGetPerfCounterInfoINTEL
#define glGetPerfMonitorCounterDataAMD                gl3wGetPerfMonitorCounterDataAMD
#define glGetPerfMonitorCounterInfoAMD                gl3wGetPerfMonitorCounterInfoAMD
#define glGetPerfMonitorCounterStringAMD              gl3wGetPerfMonitorCounterStringAMD
#define glGetPerfMonitorCountersAMD                   gl3wGetPerfMonitorCountersAMD
#define glGetPerfMonitorGroupStringAMD                gl3wGetPerfMonitorGroupStringAMD
#define glGetPerfMonitorGroupsAMD                     gl3wGetPerfMonitorGroupsAMD
#define glGetPerfQueryDataINTEL                       gl3wGetPerfQueryDataINTEL
#define glGetPerfQueryIdByNameINTEL                   gl3wGetPerfQueryIdByNameINTEL
#define glGetPerfQueryInfoINTEL                       gl3wGetPerfQueryInfoINTEL
#define glGetPointerIndexedvEXT                       gl3wGetPointerIndexedvEXT
#define glGetPointeri_vEXT                            gl3wGetPointeri_vEXT
#define glGetPointerv                                 gl3wGetPointerv
#define glGetProgramBinary                            gl3wGetProgramBinary
#define glGetProgramInfoLog                           gl3wGetProgramInfoLog
#define glGetProgramInterfaceiv                       gl3wGetProgramInterfaceiv
#define glGetProgramPipelineInfoLog                   gl3wGetProgramPipelineInfoLog
#define glGetProgramPipelineiv                        gl3wGetProgramPipelineiv
#define glGetProgramResourceIndex                     gl3wGetProgramResourceIndex
#define glGetProgramResourceLocation                  gl3wGetProgramResourceLocation
#define glGetProgramResourceLocationIndex             gl3wGetProgramResourceLocationIndex
#define glGetProgramResourceName                      gl3wGetProgramResourceName
#define glGetProgramResourcefvNV                      gl3wGetProgramResourcefvNV
#define glGetProgramResourceiv                        gl3wGetProgramResourceiv
#define glGetProgramStageiv                           gl3wGetProgramStageiv
#define glGetProgramiv                                gl3wGetProgramiv
#define glGetQueryBufferObjecti64v                    gl3wGetQueryBufferObjecti64v
#define glGetQueryBufferObjectiv                      gl3wGetQueryBufferObjectiv
#define glGetQueryBufferObjectui64v                   gl3wGetQueryBufferObjectui64v
#define glGetQueryBufferObjectuiv                     gl3wGetQueryBufferObjectuiv
#define glGetQueryIndexediv                           gl3wGetQueryIndexediv
#define glGetQueryObjecti64v                          gl3wGetQueryObjecti64v
#define glGetQueryObjectiv                            gl3wGetQueryObjectiv
#define glGetQueryObjectui64v                         gl3wGetQueryObjectui64v
#define glGetQueryObjectuiv                           gl3wGetQueryObjectuiv
#define glGetQueryiv                                  gl3wGetQueryiv
#define glGetRenderbufferParameteriv                  gl3wGetRenderbufferParameteriv
#define glGetSamplerParameterIiv                      gl3wGetSamplerParameterIiv
#define glGetSamplerParameterIuiv                     gl3wGetSamplerParameterIuiv
#define glGetSamplerParameterfv                       gl3wGetSamplerParameterfv
#define glGetSamplerParameteriv                       gl3wGetSamplerParameteriv
#define glGetShaderInfoLog                            gl3wGetShaderInfoLog
#define glGetShaderPrecisionFormat                    gl3wGetShaderPrecisionFormat
#define glGetShaderSource                             gl3wGetShaderSource
#define glGetShaderiv                                 gl3wGetShaderiv
#define glGetStageIndexNV                             gl3wGetStageIndexNV
#define glGetString                                   gl3wGetString
#define glGetStringi                                  gl3wGetStringi
#define glGetSubroutineIndex                          gl3wGetSubroutineIndex
#define glGetSubroutineUniformLocation                gl3wGetSubroutineUniformLocation
#define glGetSynciv                                   gl3wGetSynciv
#define glGetTexImage                                 gl3wGetTexImage
#define glGetTexLevelParameterfv                      gl3wGetTexLevelParameterfv
#define glGetTexLevelParameteriv                      gl3wGetTexLevelParameteriv
#define glGetTexParameterIiv                          gl3wGetTexParameterIiv
#define glGetTexParameterIuiv                         gl3wGetTexParameterIuiv
#define glGetTexParameterfv                           gl3wGetTexParameterfv
#define glGetTexParameteriv                           gl3wGetTexParameteriv
#define glGetTextureHandleARB                         gl3wGetTextureHandleARB
#define glGetTextureHandleNV                          gl3wGetTextureHandleNV
#define glGetTextureImage                             gl3wGetTextureImage
#define glGetTextureImageEXT                          gl3wGetTextureImageEXT
#define glGetTextureLevelParameterfv                  gl3wGetTextureLevelParameterfv
#define glGetTextureLevelParameterfvEXT               gl3wGetTextureLevelParameterfvEXT
#define glGetTextureLevelParameteriv                  gl3wGetTextureLevelParameteriv
#define glGetTextureLevelParameterivEXT               gl3wGetTextureLevelParameterivEXT
#define glGetTextureParameterIiv                      gl3wGetTextureParameterIiv
#define glGetTextureParameterIivEXT                   gl3wGetTextureParameterIivEXT
#define glGetTextureParameterIuiv                     gl3wGetTextureParameterIuiv
#define glGetTextureParameterIuivEXT                  gl3wGetTextureParameterIuivEXT
#define glGetTextureParameterfv                       gl3wGetTextureParameterfv
#define glGetTextureParameterfvEXT                    gl3wGetTextureParameterfvEXT
#define glGetTextureParameteriv                       gl3wGetTextureParameteriv
#define glGetTextureParameterivEXT                    gl3wGetTextureParameterivEXT
#define glGetTextureSamplerHandleARB                  gl3wGetTextureSamplerHandleARB
#define glGetTextureSamplerHandleNV                   gl3wGetTextureSamplerHandleNV
#define glGetTextureSubImage                          gl3wGetTextureSubImage
#define glGetTransformFeedbackVarying                 gl3wGetTransformFeedbackVarying
#define glGetTransformFeedbacki64_v                   gl3wGetTransformFeedbacki64_v
#define glGetTransformFeedbacki_v                     gl3wGetTransformFeedbacki_v
#define glGetTransformFeedbackiv                      gl3wGetTransformFeedbackiv
#define glGetUniformBlockIndex                        gl3wGetUniformBlockIndex
#define glGetUniformIndices                           gl3wGetUniformIndices
#define glGetUniformLocation                          gl3wGetUniformLocation
#define glGetUniformSubroutineuiv                     gl3wGetUniformSubroutineuiv
#define glGetUniformdv                                gl3wGetUniformdv
#define glGetUniformfv                                gl3wGetUniformfv
#define glGetUniformi64vARB                           gl3wGetUniformi64vARB
#define glGetUniformi64vNV                            gl3wGetUniformi64vNV
#define glGetUniformiv                                gl3wGetUniformiv
#define glGetUniformui64vARB                          gl3wGetUniformui64vARB
#define glGetUniformui64vNV                           gl3wGetUniformui64vNV
#define glGetUniformuiv                               gl3wGetUniformuiv
#define glGetVertexArrayIndexed64iv                   gl3wGetVertexArrayIndexed64iv
#define glGetVertexArrayIndexediv                     gl3wGetVertexArrayIndexediv
#define glGetVertexArrayIntegeri_vEXT                 gl3wGetVertexArrayIntegeri_vEXT
#define glGetVertexArrayIntegervEXT                   gl3wGetVertexArrayIntegervEXT
#define glGetVertexArrayPointeri_vEXT                 gl3wGetVertexArrayPointeri_vEXT
#define glGetVertexArrayPointervEXT                   gl3wGetVertexArrayPointervEXT
#define glGetVertexArrayiv                            gl3wGetVertexArrayiv
#define glGetVertexAttribIiv                          gl3wGetVertexAttribIiv
#define glGetVertexAttribIuiv                         gl3wGetVertexAttribIuiv
#define glGetVertexAttribLdv                          gl3wGetVertexAttribLdv
#define glGetVertexAttribLi64vNV                      gl3wGetVertexAttribLi64vNV
#define glGetVertexAttribLui64vARB                    gl3wGetVertexAttribLui64vARB
#define glGetVertexAttribLui64vNV                     gl3wGetVertexAttribLui64vNV
#define glGetVertexAttribPointerv                     gl3wGetVertexAttribPointerv
#define glGetVertexAttribdv                           gl3wGetVertexAttribdv
#define glGetVertexAttribfv                           gl3wGetVertexAttribfv
#define glGetVertexAttribiv                           gl3wGetVertexAttribiv
#define glGetVkProcAddrNV                             gl3wGetVkProcAddrNV
#define glGetnCompressedTexImage                      gl3wGetnCompressedTexImage
#define glGetnCompressedTexImageARB                   gl3wGetnCompressedTexImageARB
#define glGetnTexImage                                gl3wGetnTexImage
#define glGetnTexImageARB                             gl3wGetnTexImageARB
#define glGetnUniformdv                               gl3wGetnUniformdv
#define glGetnUniformdvARB                            gl3wGetnUniformdvARB
#define glGetnUniformfv                               gl3wGetnUniformfv
#define glGetnUniformfvARB                            gl3wGetnUniformfvARB
#define glGetnUniformi64vARB                          gl3wGetnUniformi64vARB
#define glGetnUniformiv                               gl3wGetnUniformiv
#define glGetnUniformivARB                            gl3wGetnUniformivARB
#define glGetnUniformui64vARB                         gl3wGetnUniformui64vARB
#define glGetnUniformuiv                              gl3wGetnUniformuiv
#define glGetnUniformuivARB                           gl3wGetnUniformuivARB
#define glHint                                        gl3wHint
#define glIndexFormatNV                               gl3wIndexFormatNV
#define glInsertEventMarkerEXT                        gl3wInsertEventMarkerEXT
#define glInterpolatePathsNV                          gl3wInterpolatePathsNV
#define glInvalidateBufferData                        gl3wInvalidateBufferData
#define glInvalidateBufferSubData                     gl3wInvalidateBufferSubData
#define glInvalidateFramebuffer                       gl3wInvalidateFramebuffer
#define glInvalidateNamedFramebufferData              gl3wInvalidateNamedFramebufferData
#define glInvalidateNamedFramebufferSubData           gl3wInvalidateNamedFramebufferSubData
#define glInvalidateSubFramebuffer                    gl3wInvalidateSubFramebuffer
#define glInvalidateTexImage                          gl3wInvalidateTexImage
#define glInvalidateTexSubImage                       gl3wInvalidateTexSubImage
#define glIsBuffer                                    gl3wIsBuffer
#define glIsBufferResidentNV                          gl3wIsBufferResidentNV
#define glIsCommandListNV                             gl3wIsCommandListNV
#define glIsEnabled                                   gl3wIsEnabled
#define glIsEnabledIndexedEXT                         gl3wIsEnabledIndexedEXT
#define glIsEnabledi                                  gl3wIsEnabledi
#define glIsFramebuffer                               gl3wIsFramebuffer
#define glIsImageHandleResidentARB                    gl3wIsImageHandleResidentARB
#define glIsImageHandleResidentNV                     gl3wIsImageHandleResidentNV
#define glIsNamedBufferResidentNV                     gl3wIsNamedBufferResidentNV
#define glIsNamedStringARB                            gl3wIsNamedStringARB
#define glIsPathNV                                    gl3wIsPathNV
#define glIsPointInFillPathNV                         gl3wIsPointInFillPathNV
#define glIsPointInStrokePathNV                       gl3wIsPointInStrokePathNV
#define glIsProgram                                   gl3wIsProgram
#define glIsProgramPipeline                           gl3wIsProgramPipeline
#define glIsQuery                                     gl3wIsQuery
#define glIsRenderbuffer                              gl3wIsRenderbuffer
#define glIsSampler                                   gl3wIsSampler
#define glIsShader                                    gl3wIsShader
#define glIsStateNV                                   gl3wIsStateNV
#define glIsSync                                      gl3wIsSync
#define glIsTexture                                   gl3wIsTexture
#define glIsTextureHandleResidentARB                  gl3wIsTextureHandleResidentARB
#define glIsTextureHandleResidentNV                   gl3wIsTextureHandleResidentNV
#define glIsTransformFeedback                         gl3wIsTransformFeedback
#define glIsVertexArray                               gl3wIsVertexArray
#define glLabelObjectEXT                              gl3wLabelObjectEXT
#define glLineWidth                                   gl3wLineWidth
#define glLinkProgram                                 gl3wLinkProgram
#define glListDrawCommandsStatesClientNV              gl3wListDrawCommandsStatesClientNV
#define glLogicOp                                     gl3wLogicOp
#define glMakeBufferNonResidentNV                     gl3wMakeBufferNonResidentNV
#define glMakeBufferResidentNV                        gl3wMakeBufferResidentNV
#define glMakeImageHandleNonResidentARB               gl3wMakeImageHandleNonResidentARB
#define glMakeImageHandleNonResidentNV                gl3wMakeImageHandleNonResidentNV
#define glMakeImageHandleResidentARB                  gl3wMakeImageHandleResidentARB
#define glMakeImageHandleResidentNV                   gl3wMakeImageHandleResidentNV
#define glMakeNamedBufferNonResidentNV                gl3wMakeNamedBufferNonResidentNV
#define glMakeNamedBufferResidentNV                   gl3wMakeNamedBufferResidentNV
#define glMakeTextureHandleNonResidentARB             gl3wMakeTextureHandleNonResidentARB
#define glMakeTextureHandleNonResidentNV              gl3wMakeTextureHandleNonResidentNV
#define glMakeTextureHandleResidentARB                gl3wMakeTextureHandleResidentARB
#define glMakeTextureHandleResidentNV                 gl3wMakeTextureHandleResidentNV
#define glMapBuffer                                   gl3wMapBuffer
#define glMapBufferRange                              gl3wMapBufferRange
#define glMapNamedBuffer                              gl3wMapNamedBuffer
#define glMapNamedBufferEXT                           gl3wMapNamedBufferEXT
#define glMapNamedBufferRange                         gl3wMapNamedBufferRange
#define glMapNamedBufferRangeEXT                      gl3wMapNamedBufferRangeEXT
#define glMatrixFrustumEXT                            gl3wMatrixFrustumEXT
#define glMatrixLoad3x2fNV                            gl3wMatrixLoad3x2fNV
#define glMatrixLoad3x3fNV                            gl3wMatrixLoad3x3fNV
#define glMatrixLoadIdentityEXT                       gl3wMatrixLoadIdentityEXT
#define glMatrixLoadTranspose3x3fNV                   gl3wMatrixLoadTranspose3x3fNV
#define glMatrixLoadTransposedEXT                     gl3wMatrixLoadTransposedEXT
#define glMatrixLoadTransposefEXT                     gl3wMatrixLoadTransposefEXT
#define glMatrixLoaddEXT                              gl3wMatrixLoaddEXT
#define glMatrixLoadfEXT                              gl3wMatrixLoadfEXT
#define glMatrixMult3x2fNV                            gl3wMatrixMult3x2fNV
#define glMatrixMult3x3fNV                            gl3wMatrixMult3x3fNV
#define glMatrixMultTranspose3x3fNV                   gl3wMatrixMultTranspose3x3fNV
#define glMatrixMultTransposedEXT                     gl3wMatrixMultTransposedEXT
#define glMatrixMultTransposefEXT                     gl3wMatrixMultTransposefEXT
#define glMatrixMultdEXT                              gl3wMatrixMultdEXT
#define glMatrixMultfEXT                              gl3wMatrixMultfEXT
#define glMatrixOrthoEXT                              gl3wMatrixOrthoEXT
#define glMatrixPopEXT                                gl3wMatrixPopEXT
#define glMatrixPushEXT                               gl3wMatrixPushEXT
#define glMatrixRotatedEXT                            gl3wMatrixRotatedEXT
#define glMatrixRotatefEXT                            gl3wMatrixRotatefEXT
#define glMatrixScaledEXT                             gl3wMatrixScaledEXT
#define glMatrixScalefEXT                             gl3wMatrixScalefEXT
#define glMatrixTranslatedEXT                         gl3wMatrixTranslatedEXT
#define glMatrixTranslatefEXT                         gl3wMatrixTranslatefEXT
#define glMaxShaderCompilerThreadsARB                 gl3wMaxShaderCompilerThreadsARB
#define glMaxShaderCompilerThreadsKHR                 gl3wMaxShaderCompilerThreadsKHR
#define glMemoryBarrier                               gl3wMemoryBarrier
#define glMemoryBarrierByRegion                       gl3wMemoryBarrierByRegion
#define glMinSampleShading                            gl3wMinSampleShading
#define glMinSampleShadingARB                         gl3wMinSampleShadingARB
#define glMultiDrawArrays                             gl3wMultiDrawArrays
#define glMultiDrawArraysIndirect                     gl3wMultiDrawArraysIndirect
#define glMultiDrawArraysIndirectBindlessCountNV      gl3wMultiDrawArraysIndirectBindlessCountNV
#define glMultiDrawArraysIndirectBindlessNV           gl3wMultiDrawArraysIndirectBindlessNV
#define glMultiDrawArraysIndirectCount                gl3wMultiDrawArraysIndirectCount
#define glMultiDrawArraysIndirectCountARB             gl3wMultiDrawArraysIndirectCountARB
#define glMultiDrawElements                           gl3wMultiDrawElements
#define glMultiDrawElementsBaseVertex                 gl3wMultiDrawElementsBaseVertex
#define glMultiDrawElementsIndirect                   gl3wMultiDrawElementsIndirect
#define glMultiDrawElementsIndirectBindlessCountNV    gl3wMultiDrawElementsIndirectBindlessCountNV
#define glMultiDrawElementsIndirectBindlessNV         gl3wMultiDrawElementsIndirectBindlessNV
#define glMultiDrawElementsIndirectCount              gl3wMultiDrawElementsIndirectCount
#define glMultiDrawElementsIndirectCountARB           gl3wMultiDrawElementsIndirectCountARB
#define glMultiTexBufferEXT                           gl3wMultiTexBufferEXT
#define glMultiTexCoordPointerEXT                     gl3wMultiTexCoordPointerEXT
#define glMultiTexEnvfEXT                             gl3wMultiTexEnvfEXT
#define glMultiTexEnvfvEXT                            gl3wMultiTexEnvfvEXT
#define glMultiTexEnviEXT                             gl3wMultiTexEnviEXT
#define glMultiTexEnvivEXT                            gl3wMultiTexEnvivEXT
#define glMultiTexGendEXT                             gl3wMultiTexGendEXT
#define glMultiTexGendvEXT                            gl3wMultiTexGendvEXT
#define glMultiTexGenfEXT                             gl3wMultiTexGenfEXT
#define glMultiTexGenfvEXT                            gl3wMultiTexGenfvEXT
#define glMultiTexGeniEXT                             gl3wMultiTexGeniEXT
#define glMultiTexGenivEXT                            gl3wMultiTexGenivEXT
#define glMultiTexImage1DEXT                          gl3wMultiTexImage1DEXT
#define glMultiTexImage2DEXT                          gl3wMultiTexImage2DEXT
#define glMultiTexImage3DEXT                          gl3wMultiTexImage3DEXT
#define glMultiTexParameterIivEXT                     gl3wMultiTexParameterIivEXT
#define glMultiTexParameterIuivEXT                    gl3wMultiTexParameterIuivEXT
#define glMultiTexParameterfEXT                       gl3wMultiTexParameterfEXT
#define glMultiTexParameterfvEXT                      gl3wMultiTexParameterfvEXT
#define glMultiTexParameteriEXT                       gl3wMultiTexParameteriEXT
#define glMultiTexParameterivEXT                      gl3wMultiTexParameterivEXT
#define glMultiTexRenderbufferEXT                     gl3wMultiTexRenderbufferEXT
#define glMultiTexSubImage1DEXT                       gl3wMultiTexSubImage1DEXT
#define glMultiTexSubImage2DEXT                       gl3wMultiTexSubImage2DEXT
#define glMultiTexSubImage3DEXT                       gl3wMultiTexSubImage3DEXT
#define glNamedBufferData                             gl3wNamedBufferData
#define glNamedBufferDataEXT                          gl3wNamedBufferDataEXT
#define glNamedBufferPageCommitmentARB                gl3wNamedBufferPageCommitmentARB
#define glNamedBufferPageCommitmentEXT                gl3wNamedBufferPageCommitmentEXT
#define glNamedBufferStorage                          gl3wNamedBufferStorage
#define glNamedBufferStorageEXT                       gl3wNamedBufferStorageEXT
#define glNamedBufferSubData                          gl3wNamedBufferSubData
#define glNamedBufferSubDataEXT                       gl3wNamedBufferSubDataEXT
#define glNamedCopyBufferSubDataEXT                   gl3wNamedCopyBufferSubDataEXT
#define glNamedFramebufferDrawBuffer                  gl3wNamedFramebufferDrawBuffer
#define glNamedFramebufferDrawBuffers                 gl3wNamedFramebufferDrawBuffers
#define glNamedFramebufferParameteri                  gl3wNamedFramebufferParameteri
#define glNamedFramebufferParameteriEXT               gl3wNamedFramebufferParameteriEXT
#define glNamedFramebufferReadBuffer                  gl3wNamedFramebufferReadBuffer
#define glNamedFramebufferRenderbuffer                gl3wNamedFramebufferRenderbuffer
#define glNamedFramebufferRenderbufferEXT             gl3wNamedFramebufferRenderbufferEXT
#define glNamedFramebufferSampleLocationsfvARB        gl3wNamedFramebufferSampleLocationsfvARB
#define glNamedFramebufferSampleLocationsfvNV         gl3wNamedFramebufferSampleLocationsfvNV
#define glNamedFramebufferTexture                     gl3wNamedFramebufferTexture
#define glNamedFramebufferTexture1DEXT                gl3wNamedFramebufferTexture1DEXT
#define glNamedFramebufferTexture2DEXT                gl3wNamedFramebufferTexture2DEXT
#define glNamedFramebufferTexture3DEXT                gl3wNamedFramebufferTexture3DEXT
#define glNamedFramebufferTextureEXT                  gl3wNamedFramebufferTextureEXT
#define glNamedFramebufferTextureFaceEXT              gl3wNamedFramebufferTextureFaceEXT
#define glNamedFramebufferTextureLayer                gl3wNamedFramebufferTextureLayer
#define glNamedFramebufferTextureLayerEXT             gl3wNamedFramebufferTextureLayerEXT
#define glNamedProgramLocalParameter4dEXT             gl3wNamedProgramLocalParameter4dEXT
#define glNamedProgramLocalParameter4dvEXT            gl3wNamedProgramLocalParameter4dvEXT
#define glNamedProgramLocalParameter4fEXT             gl3wNamedProgramLocalParameter4fEXT
#define glNamedProgramLocalParameter4fvEXT            gl3wNamedProgramLocalParameter4fvEXT
#define glNamedProgramLocalParameterI4iEXT            gl3wNamedProgramLocalParameterI4iEXT
#define glNamedProgramLocalParameterI4ivEXT           gl3wNamedProgramLocalParameterI4ivEXT
#define glNamedProgramLocalParameterI4uiEXT           gl3wNamedProgramLocalParameterI4uiEXT
#define glNamedProgramLocalParameterI4uivEXT          gl3wNamedProgramLocalParameterI4uivEXT
#define glNamedProgramLocalParameters4fvEXT           gl3wNamedProgramLocalParameters4fvEXT
#define glNamedProgramLocalParametersI4ivEXT          gl3wNamedProgramLocalParametersI4ivEXT
#define glNamedProgramLocalParametersI4uivEXT         gl3wNamedProgramLocalParametersI4uivEXT
#define glNamedProgramStringEXT                       gl3wNamedProgramStringEXT
#define glNamedRenderbufferStorage                    gl3wNamedRenderbufferStorage
#define glNamedRenderbufferStorageEXT                 gl3wNamedRenderbufferStorageEXT
#define glNamedRenderbufferStorageMultisample         gl3wNamedRenderbufferStorageMultisample
#define glNamedRenderbufferStorageMultisampleCoverageEXT gl3wNamedRenderbufferStorageMultisampleCoverageEXT
#define glNamedRenderbufferStorageMultisampleEXT      gl3wNamedRenderbufferStorageMultisampleEXT
#define glNamedStringARB                              gl3wNamedStringARB
#define glNormalFormatNV                              gl3wNormalFormatNV
#define glObjectLabel                                 gl3wObjectLabel
#define glObjectPtrLabel                              gl3wObjectPtrLabel
#define glPatchParameterfv                            gl3wPatchParameterfv
#define glPatchParameteri                             gl3wPatchParameteri
#define glPathCommandsNV                              gl3wPathCommandsNV
#define glPathCoordsNV                                gl3wPathCoordsNV
#define glPathCoverDepthFuncNV                        gl3wPathCoverDepthFuncNV
#define glPathDashArrayNV                             gl3wPathDashArrayNV
#define glPathGlyphIndexArrayNV                       gl3wPathGlyphIndexArrayNV
#define glPathGlyphIndexRangeNV                       gl3wPathGlyphIndexRangeNV
#define glPathGlyphRangeNV                            gl3wPathGlyphRangeNV
#define glPathGlyphsNV                                gl3wPathGlyphsNV
#define glPathMemoryGlyphIndexArrayNV                 gl3wPathMemoryGlyphIndexArrayNV
#define glPathParameterfNV                            gl3wPathParameterfNV
#define glPathParameterfvNV                           gl3wPathParameterfvNV
#define glPathParameteriNV                            gl3wPathParameteriNV
#define glPathParameterivNV                           gl3wPathParameterivNV
#define glPathStencilDepthOffsetNV                    gl3wPathStencilDepthOffsetNV
#define glPathStencilFuncNV                           gl3wPathStencilFuncNV
#define glPathStringNV                                gl3wPathStringNV
#define glPathSubCommandsNV                           gl3wPathSubCommandsNV
#define glPathSubCoordsNV                             gl3wPathSubCoordsNV
#define glPauseTransformFeedback                      gl3wPauseTransformFeedback
#define glPixelStoref                                 gl3wPixelStoref
#define glPixelStorei                                 gl3wPixelStorei
#define glPointAlongPathNV                            gl3wPointAlongPathNV
#define glPointParameterf                             gl3wPointParameterf
#define glPointParameterfv                            gl3wPointParameterfv
#define glPointParameteri                             gl3wPointParameteri
#define glPointParameteriv                            gl3wPointParameteriv
#define glPointSize                                   gl3wPointSize
#define glPolygonMode                                 gl3wPolygonMode
#define glPolygonOffset                               gl3wPolygonOffset
#define glPolygonOffsetClamp                          gl3wPolygonOffsetClamp
#define glPolygonOffsetClampEXT                       gl3wPolygonOffsetClampEXT
#define glPopDebugGroup                               gl3wPopDebugGroup
#define glPopGroupMarkerEXT                           gl3wPopGroupMarkerEXT
#define glPrimitiveBoundingBoxARB                     gl3wPrimitiveBoundingBoxARB
#define glPrimitiveRestartIndex                       gl3wPrimitiveRestartIndex
#define glProgramBinary                               gl3wProgramBinary
#define glProgramParameteri                           gl3wProgramParameteri
#define glProgramParameteriARB                        gl3wProgramParameteriARB
#define glProgramPathFragmentInputGenNV               gl3wProgramPathFragmentInputGenNV
#define glProgramUniform1d                            gl3wProgramUniform1d
#define glProgramUniform1dEXT                         gl3wProgramUniform1dEXT
#define glProgramUniform1dv                           gl3wProgramUniform1dv
#define glProgramUniform1dvEXT                        gl3wProgramUniform1dvEXT
#define glProgramUniform1f                            gl3wProgramUniform1f
#define glProgramUniform1fEXT                         gl3wProgramUniform1fEXT
#define glProgramUniform1fv                           gl3wProgramUniform1fv
#define glProgramUniform1fvEXT                        gl3wProgramUniform1fvEXT
#define glProgramUniform1i                            gl3wProgramUniform1i
#define glProgramUniform1i64ARB                       gl3wProgramUniform1i64ARB
#define glProgramUniform1i64NV                        gl3wProgramUniform1i64NV
#define glProgramUniform1i64vARB                      gl3wProgramUniform1i64vARB
#define glProgramUniform1i64vNV                       gl3wProgramUniform1i64vNV
#define glProgramUniform1iEXT                         gl3wProgramUniform1iEXT
#define glProgramUniform1iv                           gl3wProgramUniform1iv
#define glProgramUniform1ivEXT                        gl3wProgramUniform1ivEXT
#define glProgramUniform1ui                           gl3wProgramUniform1ui
#define glProgramUniform1ui64ARB                      gl3wProgramUniform1ui64ARB
#define glProgramUniform1ui64NV                       gl3wProgramUniform1ui64NV
#define glProgramUniform1ui64vARB                     gl3wProgramUniform1ui64vARB
#define glProgramUniform1ui64vNV                      gl3wProgramUniform1ui64vNV
#define glProgramUniform1uiEXT                        gl3wProgramUniform1uiEXT
#define glProgramUniform1uiv                          gl3wProgramUniform1uiv
#define glProgramUniform1uivEXT                       gl3wProgramUniform1uivEXT
#define glProgramUniform2d                            gl3wProgramUniform2d
#define glProgramUniform2dEXT                         gl3wProgramUniform2dEXT
#define glProgramUniform2dv                           gl3wProgramUniform2dv
#define glProgramUniform2dvEXT                        gl3wProgramUniform2dvEXT
#define glProgramUniform2f                            gl3wProgramUniform2f
#define glProgramUniform2fEXT                         gl3wProgramUniform2fEXT
#define glProgramUniform2fv                           gl3wProgramUniform2fv
#define glProgramUniform2fvEXT                        gl3wProgramUniform2fvEXT
#define glProgramUniform2i                            gl3wProgramUniform2i
#define glProgramUniform2i64ARB                       gl3wProgramUniform2i64ARB
#define glProgramUniform2i64NV                        gl3wProgramUniform2i64NV
#define glProgramUniform2i64vARB                      gl3wProgramUniform2i64vARB
#define glProgramUniform2i64vNV                       gl3wProgramUniform2i64vNV
#define glProgramUniform2iEXT                         gl3wProgramUniform2iEXT
#define glProgramUniform2iv                           gl3wProgramUniform2iv
#define glProgramUniform2ivEXT                        gl3wProgramUniform2ivEXT
#define glProgramUniform2ui                           gl3wProgramUniform2ui
#define glProgramUniform2ui64ARB                      gl3wProgramUniform2ui64ARB
#define glProgramUniform2ui64NV                       gl3wProgramUniform2ui64NV
#define glProgramUniform2ui64vARB                     gl3wProgramUniform2ui64vARB
#define glProgramUniform2ui64vNV                      gl3wProgramUniform2ui64vNV
#define glProgramUniform2uiEXT                        gl3wProgramUniform2uiEXT
#define glProgramUniform2uiv                          gl3wProgramUniform2uiv
#define glProgramUniform2uivEXT                       gl3wProgramUniform2uivEXT
#define glProgramUniform3d                            gl3wProgramUniform3d
#define glProgramUniform3dEXT                         gl3wProgramUniform3dEXT
#define glProgramUniform3dv                           gl3wProgramUniform3dv
#define glProgramUniform3dvEXT                        gl3wProgramUniform3dvEXT
#define glProgramUniform3f                            gl3wProgramUniform3f
#define glProgramUniform3fEXT                         gl3wProgramUniform3fEXT
#define glProgramUniform3fv                           gl3wProgramUniform3fv
#define glProgramUniform3fvEXT                        gl3wProgramUniform3fvEXT
#define glProgramUniform3i                            gl3wProgramUniform3i
#define glProgramUniform3i64ARB                       gl3wProgramUniform3i64ARB
#define glProgramUniform3i64NV                        gl3wProgramUniform3i64NV
#define glProgramUniform3i64vARB                      gl3wProgramUniform3i64vARB
#define glProgramUniform3i64vNV                       gl3wProgramUniform3i64vNV
#define glProgramUniform3iEXT                         gl3wProgramUniform3iEXT
#define glProgramUniform3iv                           gl3wProgramUniform3iv
#define glProgramUniform3ivEXT                        gl3wProgramUniform3ivEXT
#define glProgramUniform3ui                           gl3wProgramUniform3ui
#define glProgramUniform3ui64ARB                      gl3wProgramUniform3ui64ARB
#define glProgramUniform3ui64NV                       gl3wProgramUniform3ui64NV
#define glProgramUniform3ui64vARB                     gl3wProgramUniform3ui64vARB
#define glProgramUniform3ui64vNV                      gl3wProgramUniform3ui64vNV
#define glProgramUniform3uiEXT                        gl3wProgramUniform3uiEXT
#define glProgramUniform3uiv                          gl3wProgramUniform3uiv
#define glProgramUniform3uivEXT                       gl3wProgramUniform3uivEXT
#define glProgramUniform4d                            gl3wProgramUniform4d
#define glProgramUniform4dEXT                         gl3wProgramUniform4dEXT
#define glProgramUniform4dv                           gl3wProgramUniform4dv
#define glProgramUniform4dvEXT                        gl3wProgramUniform4dvEXT
#define glProgramUniform4f                            gl3wProgramUniform4f
#define glProgramUniform4fEXT                         gl3wProgramUniform4fEXT
#define glProgramUniform4fv                           gl3wProgramUniform4fv
#define glProgramUniform4fvEXT                        gl3wProgramUniform4fvEXT
#define glProgramUniform4i                            gl3wProgramUniform4i
#define glProgramUniform4i64ARB                       gl3wProgramUniform4i64ARB
#define glProgramUniform4i64NV                        gl3wProgramUniform4i64NV
#define glProgramUniform4i64vARB                      gl3wProgramUniform4i64vARB
#define glProgramUniform4i64vNV                       gl3wProgramUniform4i64vNV
#define glProgramUniform4iEXT                         gl3wProgramUniform4iEXT
#define glProgramUniform4iv                           gl3wProgramUniform4iv
#define glProgramUniform4ivEXT                        gl3wProgramUniform4ivEXT
#define glProgramUniform4ui                           gl3wProgramUniform4ui
#define glProgramUniform4ui64ARB                      gl3wProgramUniform4ui64ARB
#define glProgramUniform4ui64NV                       gl3wProgramUniform4ui64NV
#define glProgramUniform4ui64vARB                     gl3wProgramUniform4ui64vARB
#define glProgramUniform4ui64vNV                      gl3wProgramUniform4ui64vNV
#define glProgramUniform4uiEXT                        gl3wProgramUniform4uiEXT
#define glProgramUniform4uiv                          gl3wProgramUniform4uiv
#define glProgramUniform4uivEXT                       gl3wProgramUniform4uivEXT
#define glProgramUniformHandleui64ARB                 gl3wProgramUniformHandleui64ARB
#define glProgramUniformHandleui64NV                  gl3wProgramUniformHandleui64NV
#define glProgramUniformHandleui64vARB                gl3wProgramUniformHandleui64vARB
#define glProgramUniformHandleui64vNV                 gl3wProgramUniformHandleui64vNV
#define glProgramUniformMatrix2dv                     gl3wProgramUniformMatrix2dv
#define glProgramUniformMatrix2dvEXT                  gl3wProgramUniformMatrix2dvEXT
#define glProgramUniformMatrix2fv                     gl3wProgramUniformMatrix2fv
#define glProgramUniformMatrix2fvEXT                  gl3wProgramUniformMatrix2fvEXT
#define glProgramUniformMatrix2x3dv                   gl3wProgramUniformMatrix2x3dv
#define glProgramUniformMatrix2x3dvEXT                gl3wProgramUniformMatrix2x3dvEXT
#define glProgramUniformMatrix2x3fv                   gl3wProgramUniformMatrix2x3fv
#define glProgramUniformMatrix2x3fvEXT                gl3wProgramUniformMatrix2x3fvEXT
#define glProgramUniformMatrix2x4dv                   gl3wProgramUniformMatrix2x4dv
#define glProgramUniformMatrix2x4dvEXT                gl3wProgramUniformMatrix2x4dvEXT
#define glProgramUniformMatrix2x4fv                   gl3wProgramUniformMatrix2x4fv
#define glProgramUniformMatrix2x4fvEXT                gl3wProgramUniformMatrix2x4fvEXT
#define glProgramUniformMatrix3dv                     gl3wProgramUniformMatrix3dv
#define glProgramUniformMatrix3dvEXT                  gl3wProgramUniformMatrix3dvEXT
#define glProgramUniformMatrix3fv                     gl3wProgramUniformMatrix3fv
#define glProgramUniformMatrix3fvEXT                  gl3wProgramUniformMatrix3fvEXT
#define glProgramUniformMatrix3x2dv                   gl3wProgramUniformMatrix3x2dv
#define glProgramUniformMatrix3x2dvEXT                gl3wProgramUniformMatrix3x2dvEXT
#define glProgramUniformMatrix3x2fv                   gl3wProgramUniformMatrix3x2fv
#define glProgramUniformMatrix3x2fvEXT                gl3wProgramUniformMatrix3x2fvEXT
#define glProgramUniformMatrix3x4dv                   gl3wProgramUniformMatrix3x4dv
#define glProgramUniformMatrix3x4dvEXT                gl3wProgramUniformMatrix3x4dvEXT
#define glProgramUniformMatrix3x4fv                   gl3wProgramUniformMatrix3x4fv
#define glProgramUniformMatrix3x4fvEXT                gl3wProgramUniformMatrix3x4fvEXT
#define glProgramUniformMatrix4dv                     gl3wProgramUniformMatrix4dv
#define glProgramUniformMatrix4dvEXT                  gl3wProgramUniformMatrix4dvEXT
#define glProgramUniformMatrix4fv                     gl3wProgramUniformMatrix4fv
#define glProgramUniformMatrix4fvEXT                  gl3wProgramUniformMatrix4fvEXT
#define glProgramUniformMatrix4x2dv                   gl3wProgramUniformMatrix4x2dv
#define glProgramUniformMatrix4x2dvEXT                gl3wProgramUniformMatrix4x2dvEXT
#define glProgramUniformMatrix4x2fv                   gl3wProgramUniformMatrix4x2fv
#define glProgramUniformMatrix4x2fvEXT                gl3wProgramUniformMatrix4x2fvEXT
#define glProgramUniformMatrix4x3dv                   gl3wProgramUniformMatrix4x3dv
#define glProgramUniformMatrix4x3dvEXT                gl3wProgramUniformMatrix4x3dvEXT
#define glProgramUniformMatrix4x3fv                   gl3wProgramUniformMatrix4x3fv
#define glProgramUniformMatrix4x3fvEXT                gl3wProgramUniformMatrix4x3fvEXT
#define glProgramUniformui64NV                        gl3wProgramUniformui64NV
#define glProgramUniformui64vNV                       gl3wProgramUniformui64vNV
#define glProvokingVertex                             gl3wProvokingVertex
#define glPushClientAttribDefaultEXT                  gl3wPushClientAttribDefaultEXT
#define glPushDebugGroup                              gl3wPushDebugGroup
#define glPushGroupMarkerEXT                          gl3wPushGroupMarkerEXT
#define glQueryCounter                                gl3wQueryCounter
#define glRasterSamplesEXT                            gl3wRasterSamplesEXT
#define glReadBuffer                                  gl3wReadBuffer
#define glReadPixels                                  gl3wReadPixels
#define glReadnPixels                                 gl3wReadnPixels
#define glReadnPixelsARB                              gl3wReadnPixelsARB
#define glReleaseShaderCompiler                       gl3wReleaseShaderCompiler
#define glRenderbufferStorage                         gl3wRenderbufferStorage
#define glRenderbufferStorageMultisample              gl3wRenderbufferStorageMultisample
#define glRenderbufferStorageMultisampleCoverageNV    gl3wRenderbufferStorageMultisampleCoverageNV
#define glResolveDepthValuesNV                        gl3wResolveDepthValuesNV
#define glResumeTransformFeedback                     gl3wResumeTransformFeedback
#define glSampleCoverage                              gl3wSampleCoverage
#define glSampleMaski                                 gl3wSampleMaski
#define glSamplerParameterIiv                         gl3wSamplerParameterIiv
#define glSamplerParameterIuiv                        gl3wSamplerParameterIuiv
#define glSamplerParameterf                           gl3wSamplerParameterf
#define glSamplerParameterfv                          gl3wSamplerParameterfv
#define glSamplerParameteri                           gl3wSamplerParameteri
#define glSamplerParameteriv                          gl3wSamplerParameteriv
#define glScissor                                     gl3wScissor
#define glScissorArrayv                               gl3wScissorArrayv
#define glScissorIndexed                              gl3wScissorIndexed
#define glScissorIndexedv                             gl3wScissorIndexedv
#define glSecondaryColorFormatNV                      gl3wSecondaryColorFormatNV
#define glSelectPerfMonitorCountersAMD                gl3wSelectPerfMonitorCountersAMD
#define glShaderBinary                                gl3wShaderBinary
#define glShaderSource                                gl3wShaderSource
#define glShaderStorageBlockBinding                   gl3wShaderStorageBlockBinding
#define glSignalVkFenceNV                             gl3wSignalVkFenceNV
#define glSignalVkSemaphoreNV                         gl3wSignalVkSemaphoreNV
#define glSpecializeShader                            gl3wSpecializeShader
#define glSpecializeShaderARB                         gl3wSpecializeShaderARB
#define glStateCaptureNV                              gl3wStateCaptureNV
#define glStencilFillPathInstancedNV                  gl3wStencilFillPathInstancedNV
#define glStencilFillPathNV                           gl3wStencilFillPathNV
#define glStencilFunc                                 gl3wStencilFunc
#define glStencilFuncSeparate                         gl3wStencilFuncSeparate
#define glStencilMask                                 gl3wStencilMask
#define glStencilMaskSeparate                         gl3wStencilMaskSeparate
#define glStencilOp                                   gl3wStencilOp
#define glStencilOpSeparate                           gl3wStencilOpSeparate
#define glStencilStrokePathInstancedNV                gl3wStencilStrokePathInstancedNV
#define glStencilStrokePathNV                         gl3wStencilStrokePathNV
#define glStencilThenCoverFillPathInstancedNV         gl3wStencilThenCoverFillPathInstancedNV
#define glStencilThenCoverFillPathNV                  gl3wStencilThenCoverFillPathNV
#define glStencilThenCoverStrokePathInstancedNV       gl3wStencilThenCoverStrokePathInstancedNV
#define glStencilThenCoverStrokePathNV                gl3wStencilThenCoverStrokePathNV
#define glSubpixelPrecisionBiasNV                     gl3wSubpixelPrecisionBiasNV
#define glTexBuffer                                   gl3wTexBuffer
#define glTexBufferARB                                gl3wTexBufferARB
#define glTexBufferRange                              gl3wTexBufferRange
#define glTexCoordFormatNV                            gl3wTexCoordFormatNV
#define glTexImage1D                                  gl3wTexImage1D
#define glTexImage2D                                  gl3wTexImage2D
#define glTexImage2DMultisample                       gl3wTexImage2DMultisample
#define glTexImage3D                                  gl3wTexImage3D
#define glTexImage3DMultisample                       gl3wTexImage3DMultisample
#define glTexPageCommitmentARB                        gl3wTexPageCommitmentARB
#define glTexParameterIiv                             gl3wTexParameterIiv
#define glTexParameterIuiv                            gl3wTexParameterIuiv
#define glTexParameterf                               gl3wTexParameterf
#define glTexParameterfv                              gl3wTexParameterfv
#define glTexParameteri                               gl3wTexParameteri
#define glTexParameteriv                              gl3wTexParameteriv
#define glTexStorage1D                                gl3wTexStorage1D
#define glTexStorage2D                                gl3wTexStorage2D
#define glTexStorage2DMultisample                     gl3wTexStorage2DMultisample
#define glTexStorage3D                                gl3wTexStorage3D
#define glTexStorage3DMultisample                     gl3wTexStorage3DMultisample
#define glTexSubImage1D                               gl3wTexSubImage1D
#define glTexSubImage2D                               gl3wTexSubImage2D
#define glTexSubImage3D                               gl3wTexSubImage3D
#define glTextureBarrier                              gl3wTextureBarrier
#define glTextureBarrierNV                            gl3wTextureBarrierNV
#define glTextureBuffer                               gl3wTextureBuffer
#define glTextureBufferEXT                            gl3wTextureBufferEXT
#define glTextureBufferRange                          gl3wTextureBufferRange
#define glTextureBufferRangeEXT                       gl3wTextureBufferRangeEXT
#define glTextureImage1DEXT                           gl3wTextureImage1DEXT
#define glTextureImage2DEXT                           gl3wTextureImage2DEXT
#define glTextureImage3DEXT                           gl3wTextureImage3DEXT
#define glTexturePageCommitmentEXT                    gl3wTexturePageCommitmentEXT
#define glTextureParameterIiv                         gl3wTextureParameterIiv
#define glTextureParameterIivEXT                      gl3wTextureParameterIivEXT
#define glTextureParameterIuiv                        gl3wTextureParameterIuiv
#define glTextureParameterIuivEXT                     gl3wTextureParameterIuivEXT
#define glTextureParameterf                           gl3wTextureParameterf
#define glTextureParameterfEXT                        gl3wTextureParameterfEXT
#define glTextureParameterfv                          gl3wTextureParameterfv
#define glTextureParameterfvEXT                       gl3wTextureParameterfvEXT
#define glTextureParameteri                           gl3wTextureParameteri
#define glTextureParameteriEXT                        gl3wTextureParameteriEXT
#define glTextureParameteriv                          gl3wTextureParameteriv
#define glTextureParameterivEXT                       gl3wTextureParameterivEXT
#define glTextureRenderbufferEXT                      gl3wTextureRenderbufferEXT
#define glTextureStorage1D                            gl3wTextureStorage1D
#define glTextureStorage1DEXT                         gl3wTextureStorage1DEXT
#define glTextureStorage2D                            gl3wTextureStorage2D
#define glTextureStorage2DEXT                         gl3wTextureStorage2DEXT
#define glTextureStorage2DMultisample                 gl3wTextureStorage2DMultisample
#define glTextureStorage2DMultisampleEXT              gl3wTextureStorage2DMultisampleEXT
#define glTextureStorage3D                            gl3wTextureStorage3D
#define glTextureStorage3DEXT                         gl3wTextureStorage3DEXT
#define glTextureStorage3DMultisample                 gl3wTextureStorage3DMultisample
#define glTextureStorage3DMultisampleEXT              gl3wTextureStorage3DMultisampleEXT
#define glTextureSubImage1D                           gl3wTextureSubImage1D
#define glTextureSubImage1DEXT                        gl3wTextureSubImage1DEXT
#define glTextureSubImage2D                           gl3wTextureSubImage2D
#define glTextureSubImage2DEXT                        gl3wTextureSubImage2DEXT
#define glTextureSubImage3D                           gl3wTextureSubImage3D
#define glTextureSubImage3DEXT                        gl3wTextureSubImage3DEXT
#define glTextureView                                 gl3wTextureView
#define glTransformFeedbackBufferBase                 gl3wTransformFeedbackBufferBase
#define glTransformFeedbackBufferRange                gl3wTransformFeedbackBufferRange
#define glTransformFeedbackVaryings                   gl3wTransformFeedbackVaryings
#define glTransformPathNV                             gl3wTransformPathNV
#define glUniform1d                                   gl3wUniform1d
#define glUniform1dv                                  gl3wUniform1dv
#define glUniform1f                                   gl3wUniform1f
#define glUniform1fv                                  gl3wUniform1fv
#define glUniform1i                                   gl3wUniform1i
#define glUniform1i64ARB                              gl3wUniform1i64ARB
#define glUniform1i64NV                               gl3wUniform1i64NV
#define glUniform1i64vARB                             gl3wUniform1i64vARB
#define glUniform1i64vNV                              gl3wUniform1i64vNV
#define glUniform1iv                                  gl3wUniform1iv
#define glUniform1ui                                  gl3wUniform1ui
#define glUniform1ui64ARB                             gl3wUniform1ui64ARB
#define glUniform1ui64NV                              gl3wUniform1ui64NV
#define glUniform1ui64vARB                            gl3wUniform1ui64vARB
#define glUniform1ui64vNV                             gl3wUniform1ui64vNV
#define glUniform1uiv                                 gl3wUniform1uiv
#define glUniform2d                                   gl3wUniform2d
#define glUniform2dv                                  gl3wUniform2dv
#define glUniform2f                                   gl3wUniform2f
#define glUniform2fv                                  gl3wUniform2fv
#define glUniform2i                                   gl3wUniform2i
#define glUniform2i64ARB                              gl3wUniform2i64ARB
#define glUniform2i64NV                               gl3wUniform2i64NV
#define glUniform2i64vARB                             gl3wUniform2i64vARB
#define glUniform2i64vNV                              gl3wUniform2i64vNV
#define glUniform2iv                                  gl3wUniform2iv
#define glUniform2ui                                  gl3wUniform2ui
#define glUniform2ui64ARB                             gl3wUniform2ui64ARB
#define glUniform2ui64NV                              gl3wUniform2ui64NV
#define glUniform2ui64vARB                            gl3wUniform2ui64vARB
#define glUniform2ui64vNV                             gl3wUniform2ui64vNV
#define glUniform2uiv                                 gl3wUniform2uiv
#define glUniform3d                                   gl3wUniform3d
#define glUniform3dv                                  gl3wUniform3dv
#define glUniform3f                                   gl3wUniform3f
#define glUniform3fv                                  gl3wUniform3fv
#define glUniform3i                                   gl3wUniform3i
#define glUniform3i64ARB                              gl3wUniform3i64ARB
#define glUniform3i64NV                               gl3wUniform3i64NV
#define glUniform3i64vARB                             gl3wUniform3i64vARB
#define glUniform3i64vNV                              gl3wUniform3i64vNV
#define glUniform3iv                                  gl3wUniform3iv
#define glUniform3ui                                  gl3wUniform3ui
#define glUniform3ui64ARB                             gl3wUniform3ui64ARB
#define glUniform3ui64NV                              gl3wUniform3ui64NV
#define glUniform3ui64vARB                            gl3wUniform3ui64vARB
#define glUniform3ui64vNV                             gl3wUniform3ui64vNV
#define glUniform3uiv                                 gl3wUniform3uiv
#define glUniform4d                                   gl3wUniform4d
#define glUniform4dv                                  gl3wUniform4dv
#define glUniform4f                                   gl3wUniform4f
#define glUniform4fv                                  gl3wUniform4fv
#define glUniform4i                                   gl3wUniform4i
#define glUniform4i64ARB                              gl3wUniform4i64ARB
#define glUniform4i64NV                               gl3wUniform4i64NV
#define glUniform4i64vARB                             gl3wUniform4i64vARB
#define glUniform4i64vNV                              gl3wUniform4i64vNV
#define glUniform4iv                                  gl3wUniform4iv
#define glUniform4ui                                  gl3wUniform4ui
#define glUniform4ui64ARB                             gl3wUniform4ui64ARB
#define glUniform4ui64NV                              gl3wUniform4ui64NV
#define glUniform4ui64vARB                            gl3wUniform4ui64vARB
#define glUniform4ui64vNV                             gl3wUniform4ui64vNV
#define glUniform4uiv                                 gl3wUniform4uiv
#define glUniformBlockBinding                         gl3wUniformBlockBinding
#define glUniformHandleui64ARB                        gl3wUniformHandleui64ARB
#define glUniformHandleui64NV                         gl3wUniformHandleui64NV
#define glUniformHandleui64vARB                       gl3wUniformHandleui64vARB
#define glUniformHandleui64vNV                        gl3wUniformHandleui64vNV
#define glUniformMatrix2dv                            gl3wUniformMatrix2dv
#define glUniformMatrix2fv                            gl3wUniformMatrix2fv
#define glUniformMatrix2x3dv                          gl3wUniformMatrix2x3dv
#define glUniformMatrix2x3fv                          gl3wUniformMatrix2x3fv
#define glUniformMatrix2x4dv                          gl3wUniformMatrix2x4dv
#define glUniformMatrix2x4fv                          gl3wUniformMatrix2x4fv
#define glUniformMatrix3dv                            gl3wUniformMatrix3dv
#define glUniformMatrix3fv                            gl3wUniformMatrix3fv
#define glUniformMatrix3x2dv                          gl3wUniformMatrix3x2dv
#define glUniformMatrix3x2fv                          gl3wUniformMatrix3x2fv
#define glUniformMatrix3x4dv                          gl3wUniformMatrix3x4dv
#define glUniformMatrix3x4fv                          gl3wUniformMatrix3x4fv
#define glUniformMatrix4dv                            gl3wUniformMatrix4dv
#define glUniformMatrix4fv                            gl3wUniformMatrix4fv
#define glUniformMatrix4x2dv                          gl3wUniformMatrix4x2dv
#define glUniformMatrix4x2fv                          gl3wUniformMatrix4x2fv
#define glUniformMatrix4x3dv                          gl3wUniformMatrix4x3dv
#define glUniformMatrix4x3fv                          gl3wUniformMatrix4x3fv
#define glUniformSubroutinesuiv                       gl3wUniformSubroutinesuiv
#define glUniformui64NV                               gl3wUniformui64NV
#define glUniformui64vNV                              gl3wUniformui64vNV
#define glUnmapBuffer                                 gl3wUnmapBuffer
#define glUnmapNamedBuffer                            gl3wUnmapNamedBuffer
#define glUnmapNamedBufferEXT                         gl3wUnmapNamedBufferEXT
#define glUseProgram                                  gl3wUseProgram
#define glUseProgramStages                            gl3wUseProgramStages
#define glUseShaderProgramEXT                         gl3wUseShaderProgramEXT
#define glValidateProgram                             gl3wValidateProgram
#define glValidateProgramPipeline                     gl3wValidateProgramPipeline
#define glVertexArrayAttribBinding                    gl3wVertexArrayAttribBinding
#define glVertexArrayAttribFormat                     gl3wVertexArrayAttribFormat
#define glVertexArrayAttribIFormat                    gl3wVertexArrayAttribIFormat
#define glVertexArrayAttribLFormat                    gl3wVertexArrayAttribLFormat
#define glVertexArrayBindVertexBufferEXT              gl3wVertexArrayBindVertexBufferEXT
#define glVertexArrayBindingDivisor                   gl3wVertexArrayBindingDivisor
#define glVertexArrayColorOffsetEXT                   gl3wVertexArrayColorOffsetEXT
#define glVertexArrayEdgeFlagOffsetEXT                gl3wVertexArrayEdgeFlagOffsetEXT
#define glVertexArrayElementBuffer                    gl3wVertexArrayElementBuffer
#define glVertexArrayFogCoordOffsetEXT                gl3wVertexArrayFogCoordOffsetEXT
#define glVertexArrayIndexOffsetEXT                   gl3wVertexArrayIndexOffsetEXT
#define glVertexArrayMultiTexCoordOffsetEXT           gl3wVertexArrayMultiTexCoordOffsetEXT
#define glVertexArrayNormalOffsetEXT                  gl3wVertexArrayNormalOffsetEXT
#define glVertexArraySecondaryColorOffsetEXT          gl3wVertexArraySecondaryColorOffsetEXT
#define glVertexArrayTexCoordOffsetEXT                gl3wVertexArrayTexCoordOffsetEXT
#define glVertexArrayVertexAttribBindingEXT           gl3wVertexArrayVertexAttribBindingEXT
#define glVertexArrayVertexAttribDivisorEXT           gl3wVertexArrayVertexAttribDivisorEXT
#define glVertexArrayVertexAttribFormatEXT            gl3wVertexArrayVertexAttribFormatEXT
#define glVertexArrayVertexAttribIFormatEXT           gl3wVertexArrayVertexAttribIFormatEXT
#define glVertexArrayVertexAttribIOffsetEXT           gl3wVertexArrayVertexAttribIOffsetEXT
#define glVertexArrayVertexAttribLFormatEXT           gl3wVertexArrayVertexAttribLFormatEXT
#define glVertexArrayVertexAttribLOffsetEXT           gl3wVertexArrayVertexAttribLOffsetEXT
#define glVertexArrayVertexAttribOffsetEXT            gl3wVertexArrayVertexAttribOffsetEXT
#define glVertexArrayVertexBindingDivisorEXT          gl3wVertexArrayVertexBindingDivisorEXT
#define glVertexArrayVertexBuffer                     gl3wVertexArrayVertexBuffer
#define glVertexArrayVertexBuffers                    gl3wVertexArrayVertexBuffers
#define glVertexArrayVertexOffsetEXT                  gl3wVertexArrayVertexOffsetEXT
#define glVertexAttrib1d                              gl3wVertexAttrib1d
#define glVertexAttrib1dv                             gl3wVertexAttrib1dv
#define glVertexAttrib1f                              gl3wVertexAttrib1f
#define glVertexAttrib1fv                             gl3wVertexAttrib1fv
#define glVertexAttrib1s                              gl3wVertexAttrib1s
#define glVertexAttrib1sv                             gl3wVertexAttrib1sv
#define glVertexAttrib2d                              gl3wVertexAttrib2d
#define glVertexAttrib2dv                             gl3wVertexAttrib2dv
#define glVertexAttrib2f                              gl3wVertexAttrib2f
#define glVertexAttrib2fv                             gl3wVertexAttrib2fv
#define glVertexAttrib2s                              gl3wVertexAttrib2s
#define glVertexAttrib2sv                             gl3wVertexAttrib2sv
#define glVertexAttrib3d                              gl3wVertexAttrib3d
#define glVertexAttrib3dv                             gl3wVertexAttrib3dv
#define glVertexAttrib3f                              gl3wVertexAttrib3f
#define glVertexAttrib3fv                             gl3wVertexAttrib3fv
#define glVertexAttrib3s                              gl3wVertexAttrib3s
#define glVertexAttrib3sv                             gl3wVertexAttrib3sv
#define glVertexAttrib4Nbv                            gl3wVertexAttrib4Nbv
#define glVertexAttrib4Niv                            gl3wVertexAttrib4Niv
#define glVertexAttrib4Nsv                            gl3wVertexAttrib4Nsv
#define glVertexAttrib4Nub                            gl3wVertexAttrib4Nub
#define glVertexAttrib4Nubv                           gl3wVertexAttrib4Nubv
#define glVertexAttrib4Nuiv                           gl3wVertexAttrib4Nuiv
#define glVertexAttrib4Nusv                           gl3wVertexAttrib4Nusv
#define glVertexAttrib4bv                             gl3wVertexAttrib4bv
#define glVertexAttrib4d                              gl3wVertexAttrib4d
#define glVertexAttrib4dv                             gl3wVertexAttrib4dv
#define glVertexAttrib4f                              gl3wVertexAttrib4f
#define glVertexAttrib4fv                             gl3wVertexAttrib4fv
#define glVertexAttrib4iv                             gl3wVertexAttrib4iv
#define glVertexAttrib4s                              gl3wVertexAttrib4s
#define glVertexAttrib4sv                             gl3wVertexAttrib4sv
#define glVertexAttrib4ubv                            gl3wVertexAttrib4ubv
#define glVertexAttrib4uiv                            gl3wVertexAttrib4uiv
#define glVertexAttrib4usv                            gl3wVertexAttrib4usv
#define glVertexAttribBinding                         gl3wVertexAttribBinding
#define glVertexAttribDivisor                         gl3wVertexAttribDivisor
#define glVertexAttribDivisorARB                      gl3wVertexAttribDivisorARB
#define glVertexAttribFormat                          gl3wVertexAttribFormat
#define glVertexAttribFormatNV                        gl3wVertexAttribFormatNV
#define glVertexAttribI1i                             gl3wVertexAttribI1i
#define glVertexAttribI1iv                            gl3wVertexAttribI1iv
#define glVertexAttribI1ui                            gl3wVertexAttribI1ui
#define glVertexAttribI1uiv                           gl3wVertexAttribI1uiv
#define glVertexAttribI2i                             gl3wVertexAttribI2i
#define glVertexAttribI2iv                            gl3wVertexAttribI2iv
#define glVertexAttribI2ui                            gl3wVertexAttribI2ui
#define glVertexAttribI2uiv                           gl3wVertexAttribI2uiv
#define glVertexAttribI3i                             gl3wVertexAttribI3i
#define glVertexAttribI3iv                            gl3wVertexAttribI3iv
#define glVertexAttribI3ui                            gl3wVertexAttribI3ui
#define glVertexAttribI3uiv                           gl3wVertexAttribI3uiv
#define glVertexAttribI4bv                            gl3wVertexAttribI4bv
#define glVertexAttribI4i                             gl3wVertexAttribI4i
#define glVertexAttribI4iv                            gl3wVertexAttribI4iv
#define glVertexAttribI4sv                            gl3wVertexAttribI4sv
#define glVertexAttribI4ubv                           gl3wVertexAttribI4ubv
#define glVertexAttribI4ui                            gl3wVertexAttribI4ui
#define glVertexAttribI4uiv                           gl3wVertexAttribI4uiv
#define glVertexAttribI4usv                           gl3wVertexAttribI4usv
#define glVertexAttribIFormat                         gl3wVertexAttribIFormat
#define glVertexAttribIFormatNV                       gl3wVertexAttribIFormatNV
#define glVertexAttribIPointer                        gl3wVertexAttribIPointer
#define glVertexAttribL1d                             gl3wVertexAttribL1d
#define glVertexAttribL1dv                            gl3wVertexAttribL1dv
#define glVertexAttribL1i64NV                         gl3wVertexAttribL1i64NV
#define glVertexAttribL1i64vNV                        gl3wVertexAttribL1i64vNV
#define glVertexAttribL1ui64ARB                       gl3wVertexAttribL1ui64ARB
#define glVertexAttribL1ui64NV                        gl3wVertexAttribL1ui64NV
#define glVertexAttribL1ui64vARB                      gl3wVertexAttribL1ui64vARB
#define glVertexAttribL1ui64vNV                       gl3wVertexAttribL1ui64vNV
#define glVertexAttribL2d                             gl3wVertexAttribL2d
#define glVertexAttribL2dv                            gl3wVertexAttribL2dv
#define glVertexAttribL2i64NV                         gl3wVertexAttribL2i64NV
#define glVertexAttribL2i64vNV                        gl3wVertexAttribL2i64vNV
#define glVertexAttribL2ui64NV                        gl3wVertexAttribL2ui64NV
#define glVertexAttribL2ui64vNV                       gl3wVertexAttribL2ui64vNV
#define glVertexAttribL3d                             gl3wVertexAttribL3d
#define glVertexAttribL3dv                            gl3wVertexAttribL3dv
#define glVertexAttribL3i64NV                         gl3wVertexAttribL3i64NV
#define glVertexAttribL3i64vNV                        gl3wVertexAttribL3i64vNV
#define glVertexAttribL3ui64NV                        gl3wVertexAttribL3ui64NV
#define glVertexAttribL3ui64vNV                       gl3wVertexAttribL3ui64vNV
#define glVertexAttribL4d                             gl3wVertexAttribL4d
#define glVertexAttribL4dv                            gl3wVertexAttribL4dv
#define glVertexAttribL4i64NV                         gl3wVertexAttribL4i64NV
#define glVertexAttribL4i64vNV                        gl3wVertexAttribL4i64vNV
#define glVertexAttribL4ui64NV                        gl3wVertexAttribL4ui64NV
#define glVertexAttribL4ui64vNV                       gl3wVertexAttribL4ui64vNV
#define glVertexAttribLFormat                         gl3wVertexAttribLFormat
#define glVertexAttribLFormatNV                       gl3wVertexAttribLFormatNV
#define glVertexAttribLPointer                        gl3wVertexAttribLPointer
#define glVertexAttribP1ui                            gl3wVertexAttribP1ui
#define glVertexAttribP1uiv                           gl3wVertexAttribP1uiv
#define glVertexAttribP2ui                            gl3wVertexAttribP2ui
#define glVertexAttribP2uiv                           gl3wVertexAttribP2uiv
#define glVertexAttribP3ui                            gl3wVertexAttribP3ui
#define glVertexAttribP3uiv                           gl3wVertexAttribP3uiv
#define glVertexAttribP4ui                            gl3wVertexAttribP4ui
#define glVertexAttribP4uiv                           gl3wVertexAttribP4uiv
#define glVertexAttribPointer                         gl3wVertexAttribPointer
#define glVertexBindingDivisor                        gl3wVertexBindingDivisor
#define glVertexFormatNV                              gl3wVertexFormatNV
#define glViewport                                    gl3wViewport
#define glViewportArrayv                              gl3wViewportArrayv
#define glViewportIndexedf                            gl3wViewportIndexedf
#define glViewportIndexedfv                           gl3wViewportIndexedfv
#define glViewportPositionWScaleNV                    gl3wViewportPositionWScaleNV
#define glViewportSwizzleNV                           gl3wViewportSwizzleNV
#define glWaitSync                                    gl3wWaitSync
#define glWaitVkSemaphoreNV                           gl3wWaitVkSemaphoreNV
#define glWeightPathsNV                               gl3wWeightPathsNV
#define glWindowRectanglesEXT                         gl3wWindowRectanglesEXT

#ifdef __cplusplus
}
#endif

#endif

#if defined(GL3W_IMPLEMENTATION) && !defined(GL3W_IMPLEMENTATION_DONE)
#define GL3W_IMPLEMENTATION_DONE

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN 1
#define WIN32_MEAN_AND_LEAN 1
#include <windows.h>

static HMODULE gl3w__libgl;

static void gl3w__open_libgl (void) { gl3w__libgl = LoadLibraryA("opengl32.dll"); }
static void gl3w__close_libgl(void) { FreeLibrary(gl3w__libgl); }

static GL3WglProc gl3w__get_proc(char const *proc)
{
	GL3WglProc res;

	res = (GL3WglProc) wglGetProcAddress(proc);
	if (!res)
		res = (GL3WglProc) GetProcAddress(gl3w__libgl, proc);
	return res;
}

#elif defined(__APPLE__) || defined(__APPLE_CC__)

#include <Carbon/Carbon.h>

CFBundleRef gl3w__bundle;
CFURLRef gl3w__bundleURL;

static void gl3w__open_libgl(void)
{
	gl3w__bundleURL = CFURLCreateWithFileSystemPath(kCFAllocatorDefault,
		CFSTR("/System/Library/Frameworks/OpenGL.framework"),
		kCFURLPOSIXPathStyle, true);

	gl3w__bundle = CFBundleCreate(kCFAllocatorDefault, gl3w__bundleURL);
	assert(gl3w__bundle != NULL);
}

static void gl3w__close_libgl(void)
{
	CFRelease(gl3w__bundle);
	CFRelease(gl3w__bundleURL);
}

static GL3WglProc gl3w__get_proc(char const *proc)
{
	GL3WglProc res;

	CFStringRef procname = CFStringCreateWithCString(kCFAllocatorDefault, proc,
		kCFStringEncodingASCII);
	res = (GL3WglProc) CFBundleGetFunctionPointerForName(gl3w__bundle, procname);
	CFRelease(procname);
	return res;
}

#else

#include <dlfcn.h>
#include <GL/glx.h>

static void *gl3w__libgl;
static PFNGLXGETPROCADDRESSPROC gl3w__glx_get_proc_address;

static void gl3w__open_libgl(void)
{
	gl3w__libgl = dlopen("libGL.so.1", RTLD_LAZY | RTLD_GLOBAL);
	gl3w__glx_get_proc_address = (PFNGLXGETPROCADDRESSPROC) dlsym(gl3w__libgl, "glXGetProcAddressARB");
}

static void gl3w__close_libgl(void) { dlclose(gl3w__libgl); }

static GL3WglProc gl3w__get_proc(char const *proc)
{
	GL3WglProc res;

	res = (GL3WglProc) gl3w__glx_get_proc_address((const GLubyte *) proc);
	if (!res)
		res = (GL3WglProc) dlsym(gl3w__libgl, proc);
	return res;
}

#endif

static struct {
	int major, minor;
} gl3w__version;

static int gl3w__parse_version(void)
{
	if (!glGetIntegerv)
		return -1;

	glGetIntegerv(GL_MAJOR_VERSION, &gl3w__version.major);
	glGetIntegerv(GL_MINOR_VERSION, &gl3w__version.minor);

	if (gl3w__version.major < 3)
		return -1;
	return 0;
}

static void gl3w__load_procs(void);

int gl3w_init(void)
{
	gl3w__open_libgl();
	gl3w__load_procs();
	gl3w__close_libgl();
	return gl3w__parse_version();
}

int gl3w_is_supported(int major, int minor)
{
	if (major < 3)
		return 0;
	if (gl3w__version.major == major)
		return gl3w__version.minor >= minor;
	return gl3w__version.major >= major;
}

GL3WglProc gl3w_get_proc_address(char const *proc)
{
	return gl3w__get_proc(proc);
}

PFNGLACTIVEPROGRAMEXTPROC                            gl3wActiveProgramEXT;
PFNGLACTIVESHADERPROGRAMPROC                         gl3wActiveShaderProgram;
PFNGLACTIVETEXTUREPROC                               gl3wActiveTexture;
PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC         gl3wApplyFramebufferAttachmentCMAAINTEL;
PFNGLATTACHSHADERPROC                                gl3wAttachShader;
PFNGLBEGINCONDITIONALRENDERPROC                      gl3wBeginConditionalRender;
PFNGLBEGINCONDITIONALRENDERNVPROC                    gl3wBeginConditionalRenderNV;
PFNGLBEGINPERFMONITORAMDPROC                         gl3wBeginPerfMonitorAMD;
PFNGLBEGINPERFQUERYINTELPROC                         gl3wBeginPerfQueryINTEL;
PFNGLBEGINQUERYPROC                                  gl3wBeginQuery;
PFNGLBEGINQUERYINDEXEDPROC                           gl3wBeginQueryIndexed;
PFNGLBEGINTRANSFORMFEEDBACKPROC                      gl3wBeginTransformFeedback;
PFNGLBINDATTRIBLOCATIONPROC                          gl3wBindAttribLocation;
PFNGLBINDBUFFERPROC                                  gl3wBindBuffer;
PFNGLBINDBUFFERBASEPROC                              gl3wBindBufferBase;
PFNGLBINDBUFFERRANGEPROC                             gl3wBindBufferRange;
PFNGLBINDBUFFERSBASEPROC                             gl3wBindBuffersBase;
PFNGLBINDBUFFERSRANGEPROC                            gl3wBindBuffersRange;
PFNGLBINDFRAGDATALOCATIONPROC                        gl3wBindFragDataLocation;
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC                 gl3wBindFragDataLocationIndexed;
PFNGLBINDFRAMEBUFFERPROC                             gl3wBindFramebuffer;
PFNGLBINDIMAGETEXTUREPROC                            gl3wBindImageTexture;
PFNGLBINDIMAGETEXTURESPROC                           gl3wBindImageTextures;
PFNGLBINDMULTITEXTUREEXTPROC                         gl3wBindMultiTextureEXT;
PFNGLBINDPROGRAMPIPELINEPROC                         gl3wBindProgramPipeline;
PFNGLBINDRENDERBUFFERPROC                            gl3wBindRenderbuffer;
PFNGLBINDSAMPLERPROC                                 gl3wBindSampler;
PFNGLBINDSAMPLERSPROC                                gl3wBindSamplers;
PFNGLBINDTEXTUREPROC                                 gl3wBindTexture;
PFNGLBINDTEXTUREUNITPROC                             gl3wBindTextureUnit;
PFNGLBINDTEXTURESPROC                                gl3wBindTextures;
PFNGLBINDTRANSFORMFEEDBACKPROC                       gl3wBindTransformFeedback;
PFNGLBINDVERTEXARRAYPROC                             gl3wBindVertexArray;
PFNGLBINDVERTEXBUFFERPROC                            gl3wBindVertexBuffer;
PFNGLBINDVERTEXBUFFERSPROC                           gl3wBindVertexBuffers;
PFNGLBLENDBARRIERKHRPROC                             gl3wBlendBarrierKHR;
PFNGLBLENDBARRIERNVPROC                              gl3wBlendBarrierNV;
PFNGLBLENDCOLORPROC                                  gl3wBlendColor;
PFNGLBLENDEQUATIONPROC                               gl3wBlendEquation;
PFNGLBLENDEQUATIONSEPARATEPROC                       gl3wBlendEquationSeparate;
PFNGLBLENDEQUATIONSEPARATEIPROC                      gl3wBlendEquationSeparatei;
PFNGLBLENDEQUATIONSEPARATEIARBPROC                   gl3wBlendEquationSeparateiARB;
PFNGLBLENDEQUATIONIPROC                              gl3wBlendEquationi;
PFNGLBLENDEQUATIONIARBPROC                           gl3wBlendEquationiARB;
PFNGLBLENDFUNCPROC                                   gl3wBlendFunc;
PFNGLBLENDFUNCSEPARATEPROC                           gl3wBlendFuncSeparate;
PFNGLBLENDFUNCSEPARATEIPROC                          gl3wBlendFuncSeparatei;
PFNGLBLENDFUNCSEPARATEIARBPROC                       gl3wBlendFuncSeparateiARB;
PFNGLBLENDFUNCIPROC                                  gl3wBlendFunci;
PFNGLBLENDFUNCIARBPROC                               gl3wBlendFunciARB;
PFNGLBLENDPARAMETERINVPROC                           gl3wBlendParameteriNV;
PFNGLBLITFRAMEBUFFERPROC                             gl3wBlitFramebuffer;
PFNGLBLITNAMEDFRAMEBUFFERPROC                        gl3wBlitNamedFramebuffer;
PFNGLBUFFERADDRESSRANGENVPROC                        gl3wBufferAddressRangeNV;
PFNGLBUFFERDATAPROC                                  gl3wBufferData;
PFNGLBUFFERPAGECOMMITMENTARBPROC                     gl3wBufferPageCommitmentARB;
PFNGLBUFFERSTORAGEPROC                               gl3wBufferStorage;
PFNGLBUFFERSUBDATAPROC                               gl3wBufferSubData;
PFNGLCALLCOMMANDLISTNVPROC                           gl3wCallCommandListNV;
PFNGLCHECKFRAMEBUFFERSTATUSPROC                      gl3wCheckFramebufferStatus;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC                 gl3wCheckNamedFramebufferStatus;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC              gl3wCheckNamedFramebufferStatusEXT;
PFNGLCLAMPCOLORPROC                                  gl3wClampColor;
PFNGLCLEARPROC                                       gl3wClear;
PFNGLCLEARBUFFERDATAPROC                             gl3wClearBufferData;
PFNGLCLEARBUFFERSUBDATAPROC                          gl3wClearBufferSubData;
PFNGLCLEARBUFFERFIPROC                               gl3wClearBufferfi;
PFNGLCLEARBUFFERFVPROC                               gl3wClearBufferfv;
PFNGLCLEARBUFFERIVPROC                               gl3wClearBufferiv;
PFNGLCLEARBUFFERUIVPROC                              gl3wClearBufferuiv;
PFNGLCLEARCOLORPROC                                  gl3wClearColor;
PFNGLCLEARDEPTHPROC                                  gl3wClearDepth;
PFNGLCLEARDEPTHFPROC                                 gl3wClearDepthf;
PFNGLCLEARNAMEDBUFFERDATAPROC                        gl3wClearNamedBufferData;
PFNGLCLEARNAMEDBUFFERDATAEXTPROC                     gl3wClearNamedBufferDataEXT;
PFNGLCLEARNAMEDBUFFERSUBDATAPROC                     gl3wClearNamedBufferSubData;
PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC                  gl3wClearNamedBufferSubDataEXT;
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC                     gl3wClearNamedFramebufferfi;
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC                     gl3wClearNamedFramebufferfv;
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC                     gl3wClearNamedFramebufferiv;
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC                    gl3wClearNamedFramebufferuiv;
PFNGLCLEARSTENCILPROC                                gl3wClearStencil;
PFNGLCLEARTEXIMAGEPROC                               gl3wClearTexImage;
PFNGLCLEARTEXSUBIMAGEPROC                            gl3wClearTexSubImage;
PFNGLCLIENTATTRIBDEFAULTEXTPROC                      gl3wClientAttribDefaultEXT;
PFNGLCLIENTWAITSYNCPROC                              gl3wClientWaitSync;
PFNGLCLIPCONTROLPROC                                 gl3wClipControl;
PFNGLCOLORFORMATNVPROC                               gl3wColorFormatNV;
PFNGLCOLORMASKPROC                                   gl3wColorMask;
PFNGLCOLORMASKIPROC                                  gl3wColorMaski;
PFNGLCOMMANDLISTSEGMENTSNVPROC                       gl3wCommandListSegmentsNV;
PFNGLCOMPILECOMMANDLISTNVPROC                        gl3wCompileCommandListNV;
PFNGLCOMPILESHADERPROC                               gl3wCompileShader;
PFNGLCOMPILESHADERINCLUDEARBPROC                     gl3wCompileShaderIncludeARB;
PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC                gl3wCompressedMultiTexImage1DEXT;
PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC                gl3wCompressedMultiTexImage2DEXT;
PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC                gl3wCompressedMultiTexImage3DEXT;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC             gl3wCompressedMultiTexSubImage1DEXT;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC             gl3wCompressedMultiTexSubImage2DEXT;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC             gl3wCompressedMultiTexSubImage3DEXT;
PFNGLCOMPRESSEDTEXIMAGE1DPROC                        gl3wCompressedTexImage1D;
PFNGLCOMPRESSEDTEXIMAGE2DPROC                        gl3wCompressedTexImage2D;
PFNGLCOMPRESSEDTEXIMAGE3DPROC                        gl3wCompressedTexImage3D;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC                     gl3wCompressedTexSubImage1D;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC                     gl3wCompressedTexSubImage2D;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC                     gl3wCompressedTexSubImage3D;
PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC                 gl3wCompressedTextureImage1DEXT;
PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC                 gl3wCompressedTextureImage2DEXT;
PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC                 gl3wCompressedTextureImage3DEXT;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC                 gl3wCompressedTextureSubImage1D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC              gl3wCompressedTextureSubImage1DEXT;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC                 gl3wCompressedTextureSubImage2D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC              gl3wCompressedTextureSubImage2DEXT;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC                 gl3wCompressedTextureSubImage3D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC              gl3wCompressedTextureSubImage3DEXT;
PFNGLCONSERVATIVERASTERPARAMETERFNVPROC              gl3wConservativeRasterParameterfNV;
PFNGLCONSERVATIVERASTERPARAMETERINVPROC              gl3wConservativeRasterParameteriNV;
PFNGLCOPYBUFFERSUBDATAPROC                           gl3wCopyBufferSubData;
PFNGLCOPYIMAGESUBDATAPROC                            gl3wCopyImageSubData;
PFNGLCOPYMULTITEXIMAGE1DEXTPROC                      gl3wCopyMultiTexImage1DEXT;
PFNGLCOPYMULTITEXIMAGE2DEXTPROC                      gl3wCopyMultiTexImage2DEXT;
PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC                   gl3wCopyMultiTexSubImage1DEXT;
PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC                   gl3wCopyMultiTexSubImage2DEXT;
PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC                   gl3wCopyMultiTexSubImage3DEXT;
PFNGLCOPYNAMEDBUFFERSUBDATAPROC                      gl3wCopyNamedBufferSubData;
PFNGLCOPYPATHNVPROC                                  gl3wCopyPathNV;
PFNGLCOPYTEXIMAGE1DPROC                              gl3wCopyTexImage1D;
PFNGLCOPYTEXIMAGE2DPROC                              gl3wCopyTexImage2D;
PFNGLCOPYTEXSUBIMAGE1DPROC                           gl3wCopyTexSubImage1D;
PFNGLCOPYTEXSUBIMAGE2DPROC                           gl3wCopyTexSubImage2D;
PFNGLCOPYTEXSUBIMAGE3DPROC                           gl3wCopyTexSubImage3D;
PFNGLCOPYTEXTUREIMAGE1DEXTPROC                       gl3wCopyTextureImage1DEXT;
PFNGLCOPYTEXTUREIMAGE2DEXTPROC                       gl3wCopyTextureImage2DEXT;
PFNGLCOPYTEXTURESUBIMAGE1DPROC                       gl3wCopyTextureSubImage1D;
PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC                    gl3wCopyTextureSubImage1DEXT;
PFNGLCOPYTEXTURESUBIMAGE2DPROC                       gl3wCopyTextureSubImage2D;
PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC                    gl3wCopyTextureSubImage2DEXT;
PFNGLCOPYTEXTURESUBIMAGE3DPROC                       gl3wCopyTextureSubImage3D;
PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC                    gl3wCopyTextureSubImage3DEXT;
PFNGLCOVERFILLPATHINSTANCEDNVPROC                    gl3wCoverFillPathInstancedNV;
PFNGLCOVERFILLPATHNVPROC                             gl3wCoverFillPathNV;
PFNGLCOVERSTROKEPATHINSTANCEDNVPROC                  gl3wCoverStrokePathInstancedNV;
PFNGLCOVERSTROKEPATHNVPROC                           gl3wCoverStrokePathNV;
PFNGLCOVERAGEMODULATIONNVPROC                        gl3wCoverageModulationNV;
PFNGLCOVERAGEMODULATIONTABLENVPROC                   gl3wCoverageModulationTableNV;
PFNGLCREATEBUFFERSPROC                               gl3wCreateBuffers;
PFNGLCREATECOMMANDLISTSNVPROC                        gl3wCreateCommandListsNV;
PFNGLCREATEFRAMEBUFFERSPROC                          gl3wCreateFramebuffers;
PFNGLCREATEPERFQUERYINTELPROC                        gl3wCreatePerfQueryINTEL;
PFNGLCREATEPROGRAMPROC                               gl3wCreateProgram;
PFNGLCREATEPROGRAMPIPELINESPROC                      gl3wCreateProgramPipelines;
PFNGLCREATEQUERIESPROC                               gl3wCreateQueries;
PFNGLCREATERENDERBUFFERSPROC                         gl3wCreateRenderbuffers;
PFNGLCREATESAMPLERSPROC                              gl3wCreateSamplers;
PFNGLCREATESHADERPROC                                gl3wCreateShader;
PFNGLCREATESHADERPROGRAMEXTPROC                      gl3wCreateShaderProgramEXT;
PFNGLCREATESHADERPROGRAMVPROC                        gl3wCreateShaderProgramv;
PFNGLCREATESTATESNVPROC                              gl3wCreateStatesNV;
PFNGLCREATESYNCFROMCLEVENTARBPROC                    gl3wCreateSyncFromCLeventARB;
PFNGLCREATETEXTURESPROC                              gl3wCreateTextures;
PFNGLCREATETRANSFORMFEEDBACKSPROC                    gl3wCreateTransformFeedbacks;
PFNGLCREATEVERTEXARRAYSPROC                          gl3wCreateVertexArrays;
PFNGLCULLFACEPROC                                    gl3wCullFace;
PFNGLDEBUGMESSAGECALLBACKPROC                        gl3wDebugMessageCallback;
PFNGLDEBUGMESSAGECALLBACKARBPROC                     gl3wDebugMessageCallbackARB;
PFNGLDEBUGMESSAGECONTROLPROC                         gl3wDebugMessageControl;
PFNGLDEBUGMESSAGECONTROLARBPROC                      gl3wDebugMessageControlARB;
PFNGLDEBUGMESSAGEINSERTPROC                          gl3wDebugMessageInsert;
PFNGLDEBUGMESSAGEINSERTARBPROC                       gl3wDebugMessageInsertARB;
PFNGLDELETEBUFFERSPROC                               gl3wDeleteBuffers;
PFNGLDELETECOMMANDLISTSNVPROC                        gl3wDeleteCommandListsNV;
PFNGLDELETEFRAMEBUFFERSPROC                          gl3wDeleteFramebuffers;
PFNGLDELETENAMEDSTRINGARBPROC                        gl3wDeleteNamedStringARB;
PFNGLDELETEPATHSNVPROC                               gl3wDeletePathsNV;
PFNGLDELETEPERFMONITORSAMDPROC                       gl3wDeletePerfMonitorsAMD;
PFNGLDELETEPERFQUERYINTELPROC                        gl3wDeletePerfQueryINTEL;
PFNGLDELETEPROGRAMPROC                               gl3wDeleteProgram;
PFNGLDELETEPROGRAMPIPELINESPROC                      gl3wDeleteProgramPipelines;
PFNGLDELETEQUERIESPROC                               gl3wDeleteQueries;
PFNGLDELETERENDERBUFFERSPROC                         gl3wDeleteRenderbuffers;
PFNGLDELETESAMPLERSPROC                              gl3wDeleteSamplers;
PFNGLDELETESHADERPROC                                gl3wDeleteShader;
PFNGLDELETESTATESNVPROC                              gl3wDeleteStatesNV;
PFNGLDELETESYNCPROC                                  gl3wDeleteSync;
PFNGLDELETETEXTURESPROC                              gl3wDeleteTextures;
PFNGLDELETETRANSFORMFEEDBACKSPROC                    gl3wDeleteTransformFeedbacks;
PFNGLDELETEVERTEXARRAYSPROC                          gl3wDeleteVertexArrays;
PFNGLDEPTHFUNCPROC                                   gl3wDepthFunc;
PFNGLDEPTHMASKPROC                                   gl3wDepthMask;
PFNGLDEPTHRANGEPROC                                  gl3wDepthRange;
PFNGLDEPTHRANGEARRAYVPROC                            gl3wDepthRangeArrayv;
PFNGLDEPTHRANGEINDEXEDPROC                           gl3wDepthRangeIndexed;
PFNGLDEPTHRANGEFPROC                                 gl3wDepthRangef;
PFNGLDETACHSHADERPROC                                gl3wDetachShader;
PFNGLDISABLEPROC                                     gl3wDisable;
PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC                gl3wDisableClientStateIndexedEXT;
PFNGLDISABLECLIENTSTATEIEXTPROC                      gl3wDisableClientStateiEXT;
PFNGLDISABLEINDEXEDEXTPROC                           gl3wDisableIndexedEXT;
PFNGLDISABLEVERTEXARRAYATTRIBPROC                    gl3wDisableVertexArrayAttrib;
PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC                 gl3wDisableVertexArrayAttribEXT;
PFNGLDISABLEVERTEXARRAYEXTPROC                       gl3wDisableVertexArrayEXT;
PFNGLDISABLEVERTEXATTRIBARRAYPROC                    gl3wDisableVertexAttribArray;
PFNGLDISABLEIPROC                                    gl3wDisablei;
PFNGLDISPATCHCOMPUTEPROC                             gl3wDispatchCompute;
PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC                 gl3wDispatchComputeGroupSizeARB;
PFNGLDISPATCHCOMPUTEINDIRECTPROC                     gl3wDispatchComputeIndirect;
PFNGLDRAWARRAYSPROC                                  gl3wDrawArrays;
PFNGLDRAWARRAYSINDIRECTPROC                          gl3wDrawArraysIndirect;
PFNGLDRAWARRAYSINSTANCEDPROC                         gl3wDrawArraysInstanced;
PFNGLDRAWARRAYSINSTANCEDARBPROC                      gl3wDrawArraysInstancedARB;
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC             gl3wDrawArraysInstancedBaseInstance;
PFNGLDRAWARRAYSINSTANCEDEXTPROC                      gl3wDrawArraysInstancedEXT;
PFNGLDRAWBUFFERPROC                                  gl3wDrawBuffer;
PFNGLDRAWBUFFERSPROC                                 gl3wDrawBuffers;
PFNGLDRAWCOMMANDSADDRESSNVPROC                       gl3wDrawCommandsAddressNV;
PFNGLDRAWCOMMANDSNVPROC                              gl3wDrawCommandsNV;
PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC                 gl3wDrawCommandsStatesAddressNV;
PFNGLDRAWCOMMANDSSTATESNVPROC                        gl3wDrawCommandsStatesNV;
PFNGLDRAWELEMENTSPROC                                gl3wDrawElements;
PFNGLDRAWELEMENTSBASEVERTEXPROC                      gl3wDrawElementsBaseVertex;
PFNGLDRAWELEMENTSINDIRECTPROC                        gl3wDrawElementsIndirect;
PFNGLDRAWELEMENTSINSTANCEDPROC                       gl3wDrawElementsInstanced;
PFNGLDRAWELEMENTSINSTANCEDARBPROC                    gl3wDrawElementsInstancedARB;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC           gl3wDrawElementsInstancedBaseInstance;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC             gl3wDrawElementsInstancedBaseVertex;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC gl3wDrawElementsInstancedBaseVertexBaseInstance;
PFNGLDRAWELEMENTSINSTANCEDEXTPROC                    gl3wDrawElementsInstancedEXT;
PFNGLDRAWRANGEELEMENTSPROC                           gl3wDrawRangeElements;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC                 gl3wDrawRangeElementsBaseVertex;
PFNGLDRAWTRANSFORMFEEDBACKPROC                       gl3wDrawTransformFeedback;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC              gl3wDrawTransformFeedbackInstanced;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC                 gl3wDrawTransformFeedbackStream;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC        gl3wDrawTransformFeedbackStreamInstanced;
PFNGLDRAWVKIMAGENVPROC                               gl3wDrawVkImageNV;
PFNGLEDGEFLAGFORMATNVPROC                            gl3wEdgeFlagFormatNV;
PFNGLENABLEPROC                                      gl3wEnable;
PFNGLENABLECLIENTSTATEINDEXEDEXTPROC                 gl3wEnableClientStateIndexedEXT;
PFNGLENABLECLIENTSTATEIEXTPROC                       gl3wEnableClientStateiEXT;
PFNGLENABLEINDEXEDEXTPROC                            gl3wEnableIndexedEXT;
PFNGLENABLEVERTEXARRAYATTRIBPROC                     gl3wEnableVertexArrayAttrib;
PFNGLENABLEVERTEXARRAYATTRIBEXTPROC                  gl3wEnableVertexArrayAttribEXT;
PFNGLENABLEVERTEXARRAYEXTPROC                        gl3wEnableVertexArrayEXT;
PFNGLENABLEVERTEXATTRIBARRAYPROC                     gl3wEnableVertexAttribArray;
PFNGLENABLEIPROC                                     gl3wEnablei;
PFNGLENDCONDITIONALRENDERPROC                        gl3wEndConditionalRender;
PFNGLENDCONDITIONALRENDERNVPROC                      gl3wEndConditionalRenderNV;
PFNGLENDPERFMONITORAMDPROC                           gl3wEndPerfMonitorAMD;
PFNGLENDPERFQUERYINTELPROC                           gl3wEndPerfQueryINTEL;
PFNGLENDQUERYPROC                                    gl3wEndQuery;
PFNGLENDQUERYINDEXEDPROC                             gl3wEndQueryIndexed;
PFNGLENDTRANSFORMFEEDBACKPROC                        gl3wEndTransformFeedback;
PFNGLEVALUATEDEPTHVALUESARBPROC                      gl3wEvaluateDepthValuesARB;
PFNGLFENCESYNCPROC                                   gl3wFenceSync;
PFNGLFINISHPROC                                      gl3wFinish;
PFNGLFLUSHPROC                                       gl3wFlush;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC                      gl3wFlushMappedBufferRange;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC                 gl3wFlushMappedNamedBufferRange;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC              gl3wFlushMappedNamedBufferRangeEXT;
PFNGLFOGCOORDFORMATNVPROC                            gl3wFogCoordFormatNV;
PFNGLFRAGMENTCOVERAGECOLORNVPROC                     gl3wFragmentCoverageColorNV;
PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC                    gl3wFramebufferDrawBufferEXT;
PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC                   gl3wFramebufferDrawBuffersEXT;
PFNGLFRAMEBUFFERPARAMETERIPROC                       gl3wFramebufferParameteri;
PFNGLFRAMEBUFFERREADBUFFEREXTPROC                    gl3wFramebufferReadBufferEXT;
PFNGLFRAMEBUFFERRENDERBUFFERPROC                     gl3wFramebufferRenderbuffer;
PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC             gl3wFramebufferSampleLocationsfvARB;
PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC              gl3wFramebufferSampleLocationsfvNV;
PFNGLFRAMEBUFFERTEXTUREPROC                          gl3wFramebufferTexture;
PFNGLFRAMEBUFFERTEXTURE1DPROC                        gl3wFramebufferTexture1D;
PFNGLFRAMEBUFFERTEXTURE2DPROC                        gl3wFramebufferTexture2D;
PFNGLFRAMEBUFFERTEXTURE3DPROC                        gl3wFramebufferTexture3D;
PFNGLFRAMEBUFFERTEXTUREARBPROC                       gl3wFramebufferTextureARB;
PFNGLFRAMEBUFFERTEXTUREFACEARBPROC                   gl3wFramebufferTextureFaceARB;
PFNGLFRAMEBUFFERTEXTURELAYERPROC                     gl3wFramebufferTextureLayer;
PFNGLFRAMEBUFFERTEXTURELAYERARBPROC                  gl3wFramebufferTextureLayerARB;
PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC              gl3wFramebufferTextureMultiviewOVR;
PFNGLFRONTFACEPROC                                   gl3wFrontFace;
PFNGLGENBUFFERSPROC                                  gl3wGenBuffers;
PFNGLGENFRAMEBUFFERSPROC                             gl3wGenFramebuffers;
PFNGLGENPATHSNVPROC                                  gl3wGenPathsNV;
PFNGLGENPERFMONITORSAMDPROC                          gl3wGenPerfMonitorsAMD;
PFNGLGENPROGRAMPIPELINESPROC                         gl3wGenProgramPipelines;
PFNGLGENQUERIESPROC                                  gl3wGenQueries;
PFNGLGENRENDERBUFFERSPROC                            gl3wGenRenderbuffers;
PFNGLGENSAMPLERSPROC                                 gl3wGenSamplers;
PFNGLGENTEXTURESPROC                                 gl3wGenTextures;
PFNGLGENTRANSFORMFEEDBACKSPROC                       gl3wGenTransformFeedbacks;
PFNGLGENVERTEXARRAYSPROC                             gl3wGenVertexArrays;
PFNGLGENERATEMIPMAPPROC                              gl3wGenerateMipmap;
PFNGLGENERATEMULTITEXMIPMAPEXTPROC                   gl3wGenerateMultiTexMipmapEXT;
PFNGLGENERATETEXTUREMIPMAPPROC                       gl3wGenerateTextureMipmap;
PFNGLGENERATETEXTUREMIPMAPEXTPROC                    gl3wGenerateTextureMipmapEXT;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC              gl3wGetActiveAtomicCounterBufferiv;
PFNGLGETACTIVEATTRIBPROC                             gl3wGetActiveAttrib;
PFNGLGETACTIVESUBROUTINENAMEPROC                     gl3wGetActiveSubroutineName;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC              gl3wGetActiveSubroutineUniformName;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC                gl3wGetActiveSubroutineUniformiv;
PFNGLGETACTIVEUNIFORMPROC                            gl3wGetActiveUniform;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC                   gl3wGetActiveUniformBlockName;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC                     gl3wGetActiveUniformBlockiv;
PFNGLGETACTIVEUNIFORMNAMEPROC                        gl3wGetActiveUniformName;
PFNGLGETACTIVEUNIFORMSIVPROC                         gl3wGetActiveUniformsiv;
PFNGLGETATTACHEDSHADERSPROC                          gl3wGetAttachedShaders;
PFNGLGETATTRIBLOCATIONPROC                           gl3wGetAttribLocation;
PFNGLGETBOOLEANINDEXEDVEXTPROC                       gl3wGetBooleanIndexedvEXT;
PFNGLGETBOOLEANI_VPROC                               gl3wGetBooleani_v;
PFNGLGETBOOLEANVPROC                                 gl3wGetBooleanv;
PFNGLGETBUFFERPARAMETERI64VPROC                      gl3wGetBufferParameteri64v;
PFNGLGETBUFFERPARAMETERIVPROC                        gl3wGetBufferParameteriv;
PFNGLGETBUFFERPARAMETERUI64VNVPROC                   gl3wGetBufferParameterui64vNV;
PFNGLGETBUFFERPOINTERVPROC                           gl3wGetBufferPointerv;
PFNGLGETBUFFERSUBDATAPROC                            gl3wGetBufferSubData;
PFNGLGETCOMMANDHEADERNVPROC                          gl3wGetCommandHeaderNV;
PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC               gl3wGetCompressedMultiTexImageEXT;
PFNGLGETCOMPRESSEDTEXIMAGEPROC                       gl3wGetCompressedTexImage;
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC                   gl3wGetCompressedTextureImage;
PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC                gl3wGetCompressedTextureImageEXT;
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC                gl3wGetCompressedTextureSubImage;
PFNGLGETCOVERAGEMODULATIONTABLENVPROC                gl3wGetCoverageModulationTableNV;
PFNGLGETDEBUGMESSAGELOGPROC                          gl3wGetDebugMessageLog;
PFNGLGETDEBUGMESSAGELOGARBPROC                       gl3wGetDebugMessageLogARB;
PFNGLGETDOUBLEINDEXEDVEXTPROC                        gl3wGetDoubleIndexedvEXT;
PFNGLGETDOUBLEI_VPROC                                gl3wGetDoublei_v;
PFNGLGETDOUBLEI_VEXTPROC                             gl3wGetDoublei_vEXT;
PFNGLGETDOUBLEVPROC                                  gl3wGetDoublev;
PFNGLGETERRORPROC                                    gl3wGetError;
PFNGLGETFIRSTPERFQUERYIDINTELPROC                    gl3wGetFirstPerfQueryIdINTEL;
PFNGLGETFLOATINDEXEDVEXTPROC                         gl3wGetFloatIndexedvEXT;
PFNGLGETFLOATI_VPROC                                 gl3wGetFloati_v;
PFNGLGETFLOATI_VEXTPROC                              gl3wGetFloati_vEXT;
PFNGLGETFLOATVPROC                                   gl3wGetFloatv;
PFNGLGETFRAGDATAINDEXPROC                            gl3wGetFragDataIndex;
PFNGLGETFRAGDATALOCATIONPROC                         gl3wGetFragDataLocation;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC         gl3wGetFramebufferAttachmentParameteriv;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC                   gl3wGetFramebufferParameteriv;
PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC                gl3wGetFramebufferParameterivEXT;
PFNGLGETGRAPHICSRESETSTATUSPROC                      gl3wGetGraphicsResetStatus;
PFNGLGETGRAPHICSRESETSTATUSARBPROC                   gl3wGetGraphicsResetStatusARB;
PFNGLGETIMAGEHANDLEARBPROC                           gl3wGetImageHandleARB;
PFNGLGETIMAGEHANDLENVPROC                            gl3wGetImageHandleNV;
PFNGLGETINTEGER64I_VPROC                             gl3wGetInteger64i_v;
PFNGLGETINTEGER64VPROC                               gl3wGetInteger64v;
PFNGLGETINTEGERINDEXEDVEXTPROC                       gl3wGetIntegerIndexedvEXT;
PFNGLGETINTEGERI_VPROC                               gl3wGetIntegeri_v;
PFNGLGETINTEGERUI64I_VNVPROC                         gl3wGetIntegerui64i_vNV;
PFNGLGETINTEGERUI64VNVPROC                           gl3wGetIntegerui64vNV;
PFNGLGETINTEGERVPROC                                 gl3wGetIntegerv;
PFNGLGETINTERNALFORMATSAMPLEIVNVPROC                 gl3wGetInternalformatSampleivNV;
PFNGLGETINTERNALFORMATI64VPROC                       gl3wGetInternalformati64v;
PFNGLGETINTERNALFORMATIVPROC                         gl3wGetInternalformativ;
PFNGLGETMULTITEXENVFVEXTPROC                         gl3wGetMultiTexEnvfvEXT;
PFNGLGETMULTITEXENVIVEXTPROC                         gl3wGetMultiTexEnvivEXT;
PFNGLGETMULTITEXGENDVEXTPROC                         gl3wGetMultiTexGendvEXT;
PFNGLGETMULTITEXGENFVEXTPROC                         gl3wGetMultiTexGenfvEXT;
PFNGLGETMULTITEXGENIVEXTPROC                         gl3wGetMultiTexGenivEXT;
PFNGLGETMULTITEXIMAGEEXTPROC                         gl3wGetMultiTexImageEXT;
PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC              gl3wGetMultiTexLevelParameterfvEXT;
PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC              gl3wGetMultiTexLevelParameterivEXT;
PFNGLGETMULTITEXPARAMETERIIVEXTPROC                  gl3wGetMultiTexParameterIivEXT;
PFNGLGETMULTITEXPARAMETERIUIVEXTPROC                 gl3wGetMultiTexParameterIuivEXT;
PFNGLGETMULTITEXPARAMETERFVEXTPROC                   gl3wGetMultiTexParameterfvEXT;
PFNGLGETMULTITEXPARAMETERIVEXTPROC                   gl3wGetMultiTexParameterivEXT;
PFNGLGETMULTISAMPLEFVPROC                            gl3wGetMultisamplefv;
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC                 gl3wGetNamedBufferParameteri64v;
PFNGLGETNAMEDBUFFERPARAMETERIVPROC                   gl3wGetNamedBufferParameteriv;
PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC                gl3wGetNamedBufferParameterivEXT;
PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC              gl3wGetNamedBufferParameterui64vNV;
PFNGLGETNAMEDBUFFERPOINTERVPROC                      gl3wGetNamedBufferPointerv;
PFNGLGETNAMEDBUFFERPOINTERVEXTPROC                   gl3wGetNamedBufferPointervEXT;
PFNGLGETNAMEDBUFFERSUBDATAPROC                       gl3wGetNamedBufferSubData;
PFNGLGETNAMEDBUFFERSUBDATAEXTPROC                    gl3wGetNamedBufferSubDataEXT;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC    gl3wGetNamedFramebufferAttachmentParameteriv;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC gl3wGetNamedFramebufferAttachmentParameterivEXT;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC              gl3wGetNamedFramebufferParameteriv;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC           gl3wGetNamedFramebufferParameterivEXT;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC         gl3wGetNamedProgramLocalParameterIivEXT;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC        gl3wGetNamedProgramLocalParameterIuivEXT;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC          gl3wGetNamedProgramLocalParameterdvEXT;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC          gl3wGetNamedProgramLocalParameterfvEXT;
PFNGLGETNAMEDPROGRAMSTRINGEXTPROC                    gl3wGetNamedProgramStringEXT;
PFNGLGETNAMEDPROGRAMIVEXTPROC                        gl3wGetNamedProgramivEXT;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC             gl3wGetNamedRenderbufferParameteriv;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC          gl3wGetNamedRenderbufferParameterivEXT;
PFNGLGETNAMEDSTRINGARBPROC                           gl3wGetNamedStringARB;
PFNGLGETNAMEDSTRINGIVARBPROC                         gl3wGetNamedStringivARB;
PFNGLGETNEXTPERFQUERYIDINTELPROC                     gl3wGetNextPerfQueryIdINTEL;
PFNGLGETOBJECTLABELPROC                              gl3wGetObjectLabel;
PFNGLGETOBJECTLABELEXTPROC                           gl3wGetObjectLabelEXT;
PFNGLGETOBJECTPTRLABELPROC                           gl3wGetObjectPtrLabel;
PFNGLGETPATHCOMMANDSNVPROC                           gl3wGetPathCommandsNV;
PFNGLGETPATHCOORDSNVPROC                             gl3wGetPathCoordsNV;
PFNGLGETPATHDASHARRAYNVPROC                          gl3wGetPathDashArrayNV;
PFNGLGETPATHLENGTHNVPROC                             gl3wGetPathLengthNV;
PFNGLGETPATHMETRICRANGENVPROC                        gl3wGetPathMetricRangeNV;
PFNGLGETPATHMETRICSNVPROC                            gl3wGetPathMetricsNV;
PFNGLGETPATHPARAMETERFVNVPROC                        gl3wGetPathParameterfvNV;
PFNGLGETPATHPARAMETERIVNVPROC                        gl3wGetPathParameterivNV;
PFNGLGETPATHSPACINGNVPROC                            gl3wGetPathSpacingNV;
PFNGLGETPERFCOUNTERINFOINTELPROC                     gl3wGetPerfCounterInfoINTEL;
PFNGLGETPERFMONITORCOUNTERDATAAMDPROC                gl3wGetPerfMonitorCounterDataAMD;
PFNGLGETPERFMONITORCOUNTERINFOAMDPROC                gl3wGetPerfMonitorCounterInfoAMD;
PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC              gl3wGetPerfMonitorCounterStringAMD;
PFNGLGETPERFMONITORCOUNTERSAMDPROC                   gl3wGetPerfMonitorCountersAMD;
PFNGLGETPERFMONITORGROUPSTRINGAMDPROC                gl3wGetPerfMonitorGroupStringAMD;
PFNGLGETPERFMONITORGROUPSAMDPROC                     gl3wGetPerfMonitorGroupsAMD;
PFNGLGETPERFQUERYDATAINTELPROC                       gl3wGetPerfQueryDataINTEL;
PFNGLGETPERFQUERYIDBYNAMEINTELPROC                   gl3wGetPerfQueryIdByNameINTEL;
PFNGLGETPERFQUERYINFOINTELPROC                       gl3wGetPerfQueryInfoINTEL;
PFNGLGETPOINTERINDEXEDVEXTPROC                       gl3wGetPointerIndexedvEXT;
PFNGLGETPOINTERI_VEXTPROC                            gl3wGetPointeri_vEXT;
PFNGLGETPOINTERVPROC                                 gl3wGetPointerv;
PFNGLGETPROGRAMBINARYPROC                            gl3wGetProgramBinary;
PFNGLGETPROGRAMINFOLOGPROC                           gl3wGetProgramInfoLog;
PFNGLGETPROGRAMINTERFACEIVPROC                       gl3wGetProgramInterfaceiv;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC                   gl3wGetProgramPipelineInfoLog;
PFNGLGETPROGRAMPIPELINEIVPROC                        gl3wGetProgramPipelineiv;
PFNGLGETPROGRAMRESOURCEINDEXPROC                     gl3wGetProgramResourceIndex;
PFNGLGETPROGRAMRESOURCELOCATIONPROC                  gl3wGetProgramResourceLocation;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC             gl3wGetProgramResourceLocationIndex;
PFNGLGETPROGRAMRESOURCENAMEPROC                      gl3wGetProgramResourceName;
PFNGLGETPROGRAMRESOURCEFVNVPROC                      gl3wGetProgramResourcefvNV;
PFNGLGETPROGRAMRESOURCEIVPROC                        gl3wGetProgramResourceiv;
PFNGLGETPROGRAMSTAGEIVPROC                           gl3wGetProgramStageiv;
PFNGLGETPROGRAMIVPROC                                gl3wGetProgramiv;
PFNGLGETQUERYBUFFEROBJECTI64VPROC                    gl3wGetQueryBufferObjecti64v;
PFNGLGETQUERYBUFFEROBJECTIVPROC                      gl3wGetQueryBufferObjectiv;
PFNGLGETQUERYBUFFEROBJECTUI64VPROC                   gl3wGetQueryBufferObjectui64v;
PFNGLGETQUERYBUFFEROBJECTUIVPROC                     gl3wGetQueryBufferObjectuiv;
PFNGLGETQUERYINDEXEDIVPROC                           gl3wGetQueryIndexediv;
PFNGLGETQUERYOBJECTI64VPROC                          gl3wGetQueryObjecti64v;
PFNGLGETQUERYOBJECTIVPROC                            gl3wGetQueryObjectiv;
PFNGLGETQUERYOBJECTUI64VPROC                         gl3wGetQueryObjectui64v;
PFNGLGETQUERYOBJECTUIVPROC                           gl3wGetQueryObjectuiv;
PFNGLGETQUERYIVPROC                                  gl3wGetQueryiv;
PFNGLGETRENDERBUFFERPARAMETERIVPROC                  gl3wGetRenderbufferParameteriv;
PFNGLGETSAMPLERPARAMETERIIVPROC                      gl3wGetSamplerParameterIiv;
PFNGLGETSAMPLERPARAMETERIUIVPROC                     gl3wGetSamplerParameterIuiv;
PFNGLGETSAMPLERPARAMETERFVPROC                       gl3wGetSamplerParameterfv;
PFNGLGETSAMPLERPARAMETERIVPROC                       gl3wGetSamplerParameteriv;
PFNGLGETSHADERINFOLOGPROC                            gl3wGetShaderInfoLog;
PFNGLGETSHADERPRECISIONFORMATPROC                    gl3wGetShaderPrecisionFormat;
PFNGLGETSHADERSOURCEPROC                             gl3wGetShaderSource;
PFNGLGETSHADERIVPROC                                 gl3wGetShaderiv;
PFNGLGETSTAGEINDEXNVPROC                             gl3wGetStageIndexNV;
PFNGLGETSTRINGPROC                                   gl3wGetString;
PFNGLGETSTRINGIPROC                                  gl3wGetStringi;
PFNGLGETSUBROUTINEINDEXPROC                          gl3wGetSubroutineIndex;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC                gl3wGetSubroutineUniformLocation;
PFNGLGETSYNCIVPROC                                   gl3wGetSynciv;
PFNGLGETTEXIMAGEPROC                                 gl3wGetTexImage;
PFNGLGETTEXLEVELPARAMETERFVPROC                      gl3wGetTexLevelParameterfv;
PFNGLGETTEXLEVELPARAMETERIVPROC                      gl3wGetTexLevelParameteriv;
PFNGLGETTEXPARAMETERIIVPROC                          gl3wGetTexParameterIiv;
PFNGLGETTEXPARAMETERIUIVPROC                         gl3wGetTexParameterIuiv;
PFNGLGETTEXPARAMETERFVPROC                           gl3wGetTexParameterfv;
PFNGLGETTEXPARAMETERIVPROC                           gl3wGetTexParameteriv;
PFNGLGETTEXTUREHANDLEARBPROC                         gl3wGetTextureHandleARB;
PFNGLGETTEXTUREHANDLENVPROC                          gl3wGetTextureHandleNV;
PFNGLGETTEXTUREIMAGEPROC                             gl3wGetTextureImage;
PFNGLGETTEXTUREIMAGEEXTPROC                          gl3wGetTextureImageEXT;
PFNGLGETTEXTURELEVELPARAMETERFVPROC                  gl3wGetTextureLevelParameterfv;
PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC               gl3wGetTextureLevelParameterfvEXT;
PFNGLGETTEXTURELEVELPARAMETERIVPROC                  gl3wGetTextureLevelParameteriv;
PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC               gl3wGetTextureLevelParameterivEXT;
PFNGLGETTEXTUREPARAMETERIIVPROC                      gl3wGetTextureParameterIiv;
PFNGLGETTEXTUREPARAMETERIIVEXTPROC                   gl3wGetTextureParameterIivEXT;
PFNGLGETTEXTUREPARAMETERIUIVPROC                     gl3wGetTextureParameterIuiv;
PFNGLGETTEXTUREPARAMETERIUIVEXTPROC                  gl3wGetTextureParameterIuivEXT;
PFNGLGETTEXTUREPARAMETERFVPROC                       gl3wGetTextureParameterfv;
PFNGLGETTEXTUREPARAMETERFVEXTPROC                    gl3wGetTextureParameterfvEXT;
PFNGLGETTEXTUREPARAMETERIVPROC                       gl3wGetTextureParameteriv;
PFNGLGETTEXTUREPARAMETERIVEXTPROC                    gl3wGetTextureParameterivEXT;
PFNGLGETTEXTURESAMPLERHANDLEARBPROC                  gl3wGetTextureSamplerHandleARB;
PFNGLGETTEXTURESAMPLERHANDLENVPROC                   gl3wGetTextureSamplerHandleNV;
PFNGLGETTEXTURESUBIMAGEPROC                          gl3wGetTextureSubImage;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC                 gl3wGetTransformFeedbackVarying;
PFNGLGETTRANSFORMFEEDBACKI64_VPROC                   gl3wGetTransformFeedbacki64_v;
PFNGLGETTRANSFORMFEEDBACKI_VPROC                     gl3wGetTransformFeedbacki_v;
PFNGLGETTRANSFORMFEEDBACKIVPROC                      gl3wGetTransformFeedbackiv;
PFNGLGETUNIFORMBLOCKINDEXPROC                        gl3wGetUniformBlockIndex;
PFNGLGETUNIFORMINDICESPROC                           gl3wGetUniformIndices;
PFNGLGETUNIFORMLOCATIONPROC                          gl3wGetUniformLocation;
PFNGLGETUNIFORMSUBROUTINEUIVPROC                     gl3wGetUniformSubroutineuiv;
PFNGLGETUNIFORMDVPROC                                gl3wGetUniformdv;
PFNGLGETUNIFORMFVPROC                                gl3wGetUniformfv;
PFNGLGETUNIFORMI64VARBPROC                           gl3wGetUniformi64vARB;
PFNGLGETUNIFORMI64VNVPROC                            gl3wGetUniformi64vNV;
PFNGLGETUNIFORMIVPROC                                gl3wGetUniformiv;
PFNGLGETUNIFORMUI64VARBPROC                          gl3wGetUniformui64vARB;
PFNGLGETUNIFORMUI64VNVPROC                           gl3wGetUniformui64vNV;
PFNGLGETUNIFORMUIVPROC                               gl3wGetUniformuiv;
PFNGLGETVERTEXARRAYINDEXED64IVPROC                   gl3wGetVertexArrayIndexed64iv;
PFNGLGETVERTEXARRAYINDEXEDIVPROC                     gl3wGetVertexArrayIndexediv;
PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC                 gl3wGetVertexArrayIntegeri_vEXT;
PFNGLGETVERTEXARRAYINTEGERVEXTPROC                   gl3wGetVertexArrayIntegervEXT;
PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC                 gl3wGetVertexArrayPointeri_vEXT;
PFNGLGETVERTEXARRAYPOINTERVEXTPROC                   gl3wGetVertexArrayPointervEXT;
PFNGLGETVERTEXARRAYIVPROC                            gl3wGetVertexArrayiv;
PFNGLGETVERTEXATTRIBIIVPROC                          gl3wGetVertexAttribIiv;
PFNGLGETVERTEXATTRIBIUIVPROC                         gl3wGetVertexAttribIuiv;
PFNGLGETVERTEXATTRIBLDVPROC                          gl3wGetVertexAttribLdv;
PFNGLGETVERTEXATTRIBLI64VNVPROC                      gl3wGetVertexAttribLi64vNV;
PFNGLGETVERTEXATTRIBLUI64VARBPROC                    gl3wGetVertexAttribLui64vARB;
PFNGLGETVERTEXATTRIBLUI64VNVPROC                     gl3wGetVertexAttribLui64vNV;
PFNGLGETVERTEXATTRIBPOINTERVPROC                     gl3wGetVertexAttribPointerv;
PFNGLGETVERTEXATTRIBDVPROC                           gl3wGetVertexAttribdv;
PFNGLGETVERTEXATTRIBFVPROC                           gl3wGetVertexAttribfv;
PFNGLGETVERTEXATTRIBIVPROC                           gl3wGetVertexAttribiv;
PFNGLGETVKPROCADDRNVPROC                             gl3wGetVkProcAddrNV;
PFNGLGETNCOMPRESSEDTEXIMAGEPROC                      gl3wGetnCompressedTexImage;
PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC                   gl3wGetnCompressedTexImageARB;
PFNGLGETNTEXIMAGEPROC                                gl3wGetnTexImage;
PFNGLGETNTEXIMAGEARBPROC                             gl3wGetnTexImageARB;
PFNGLGETNUNIFORMDVPROC                               gl3wGetnUniformdv;
PFNGLGETNUNIFORMDVARBPROC                            gl3wGetnUniformdvARB;
PFNGLGETNUNIFORMFVPROC                               gl3wGetnUniformfv;
PFNGLGETNUNIFORMFVARBPROC                            gl3wGetnUniformfvARB;
PFNGLGETNUNIFORMI64VARBPROC                          gl3wGetnUniformi64vARB;
PFNGLGETNUNIFORMIVPROC                               gl3wGetnUniformiv;
PFNGLGETNUNIFORMIVARBPROC                            gl3wGetnUniformivARB;
PFNGLGETNUNIFORMUI64VARBPROC                         gl3wGetnUniformui64vARB;
PFNGLGETNUNIFORMUIVPROC                              gl3wGetnUniformuiv;
PFNGLGETNUNIFORMUIVARBPROC                           gl3wGetnUniformuivARB;
PFNGLHINTPROC                                        gl3wHint;
PFNGLINDEXFORMATNVPROC                               gl3wIndexFormatNV;
PFNGLINSERTEVENTMARKEREXTPROC                        gl3wInsertEventMarkerEXT;
PFNGLINTERPOLATEPATHSNVPROC                          gl3wInterpolatePathsNV;
PFNGLINVALIDATEBUFFERDATAPROC                        gl3wInvalidateBufferData;
PFNGLINVALIDATEBUFFERSUBDATAPROC                     gl3wInvalidateBufferSubData;
PFNGLINVALIDATEFRAMEBUFFERPROC                       gl3wInvalidateFramebuffer;
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC              gl3wInvalidateNamedFramebufferData;
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC           gl3wInvalidateNamedFramebufferSubData;
PFNGLINVALIDATESUBFRAMEBUFFERPROC                    gl3wInvalidateSubFramebuffer;
PFNGLINVALIDATETEXIMAGEPROC                          gl3wInvalidateTexImage;
PFNGLINVALIDATETEXSUBIMAGEPROC                       gl3wInvalidateTexSubImage;
PFNGLISBUFFERPROC                                    gl3wIsBuffer;
PFNGLISBUFFERRESIDENTNVPROC                          gl3wIsBufferResidentNV;
PFNGLISCOMMANDLISTNVPROC                             gl3wIsCommandListNV;
PFNGLISENABLEDPROC                                   gl3wIsEnabled;
PFNGLISENABLEDINDEXEDEXTPROC                         gl3wIsEnabledIndexedEXT;
PFNGLISENABLEDIPROC                                  gl3wIsEnabledi;
PFNGLISFRAMEBUFFERPROC                               gl3wIsFramebuffer;
PFNGLISIMAGEHANDLERESIDENTARBPROC                    gl3wIsImageHandleResidentARB;
PFNGLISIMAGEHANDLERESIDENTNVPROC                     gl3wIsImageHandleResidentNV;
PFNGLISNAMEDBUFFERRESIDENTNVPROC                     gl3wIsNamedBufferResidentNV;
PFNGLISNAMEDSTRINGARBPROC                            gl3wIsNamedStringARB;
PFNGLISPATHNVPROC                                    gl3wIsPathNV;
PFNGLISPOINTINFILLPATHNVPROC                         gl3wIsPointInFillPathNV;
PFNGLISPOINTINSTROKEPATHNVPROC                       gl3wIsPointInStrokePathNV;
PFNGLISPROGRAMPROC                                   gl3wIsProgram;
PFNGLISPROGRAMPIPELINEPROC                           gl3wIsProgramPipeline;
PFNGLISQUERYPROC                                     gl3wIsQuery;
PFNGLISRENDERBUFFERPROC                              gl3wIsRenderbuffer;
PFNGLISSAMPLERPROC                                   gl3wIsSampler;
PFNGLISSHADERPROC                                    gl3wIsShader;
PFNGLISSTATENVPROC                                   gl3wIsStateNV;
PFNGLISSYNCPROC                                      gl3wIsSync;
PFNGLISTEXTUREPROC                                   gl3wIsTexture;
PFNGLISTEXTUREHANDLERESIDENTARBPROC                  gl3wIsTextureHandleResidentARB;
PFNGLISTEXTUREHANDLERESIDENTNVPROC                   gl3wIsTextureHandleResidentNV;
PFNGLISTRANSFORMFEEDBACKPROC                         gl3wIsTransformFeedback;
PFNGLISVERTEXARRAYPROC                               gl3wIsVertexArray;
PFNGLLABELOBJECTEXTPROC                              gl3wLabelObjectEXT;
PFNGLLINEWIDTHPROC                                   gl3wLineWidth;
PFNGLLINKPROGRAMPROC                                 gl3wLinkProgram;
PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC              gl3wListDrawCommandsStatesClientNV;
PFNGLLOGICOPPROC                                     gl3wLogicOp;
PFNGLMAKEBUFFERNONRESIDENTNVPROC                     gl3wMakeBufferNonResidentNV;
PFNGLMAKEBUFFERRESIDENTNVPROC                        gl3wMakeBufferResidentNV;
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC               gl3wMakeImageHandleNonResidentARB;
PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC                gl3wMakeImageHandleNonResidentNV;
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC                  gl3wMakeImageHandleResidentARB;
PFNGLMAKEIMAGEHANDLERESIDENTNVPROC                   gl3wMakeImageHandleResidentNV;
PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC                gl3wMakeNamedBufferNonResidentNV;
PFNGLMAKENAMEDBUFFERRESIDENTNVPROC                   gl3wMakeNamedBufferResidentNV;
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC             gl3wMakeTextureHandleNonResidentARB;
PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC              gl3wMakeTextureHandleNonResidentNV;
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC                gl3wMakeTextureHandleResidentARB;
PFNGLMAKETEXTUREHANDLERESIDENTNVPROC                 gl3wMakeTextureHandleResidentNV;
PFNGLMAPBUFFERPROC                                   gl3wMapBuffer;
PFNGLMAPBUFFERRANGEPROC                              gl3wMapBufferRange;
PFNGLMAPNAMEDBUFFERPROC                              gl3wMapNamedBuffer;
PFNGLMAPNAMEDBUFFEREXTPROC                           gl3wMapNamedBufferEXT;
PFNGLMAPNAMEDBUFFERRANGEPROC                         gl3wMapNamedBufferRange;
PFNGLMAPNAMEDBUFFERRANGEEXTPROC                      gl3wMapNamedBufferRangeEXT;
PFNGLMATRIXFRUSTUMEXTPROC                            gl3wMatrixFrustumEXT;
PFNGLMATRIXLOAD3X2FNVPROC                            gl3wMatrixLoad3x2fNV;
PFNGLMATRIXLOAD3X3FNVPROC                            gl3wMatrixLoad3x3fNV;
PFNGLMATRIXLOADIDENTITYEXTPROC                       gl3wMatrixLoadIdentityEXT;
PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC                   gl3wMatrixLoadTranspose3x3fNV;
PFNGLMATRIXLOADTRANSPOSEDEXTPROC                     gl3wMatrixLoadTransposedEXT;
PFNGLMATRIXLOADTRANSPOSEFEXTPROC                     gl3wMatrixLoadTransposefEXT;
PFNGLMATRIXLOADDEXTPROC                              gl3wMatrixLoaddEXT;
PFNGLMATRIXLOADFEXTPROC                              gl3wMatrixLoadfEXT;
PFNGLMATRIXMULT3X2FNVPROC                            gl3wMatrixMult3x2fNV;
PFNGLMATRIXMULT3X3FNVPROC                            gl3wMatrixMult3x3fNV;
PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC                   gl3wMatrixMultTranspose3x3fNV;
PFNGLMATRIXMULTTRANSPOSEDEXTPROC                     gl3wMatrixMultTransposedEXT;
PFNGLMATRIXMULTTRANSPOSEFEXTPROC                     gl3wMatrixMultTransposefEXT;
PFNGLMATRIXMULTDEXTPROC                              gl3wMatrixMultdEXT;
PFNGLMATRIXMULTFEXTPROC                              gl3wMatrixMultfEXT;
PFNGLMATRIXORTHOEXTPROC                              gl3wMatrixOrthoEXT;
PFNGLMATRIXPOPEXTPROC                                gl3wMatrixPopEXT;
PFNGLMATRIXPUSHEXTPROC                               gl3wMatrixPushEXT;
PFNGLMATRIXROTATEDEXTPROC                            gl3wMatrixRotatedEXT;
PFNGLMATRIXROTATEFEXTPROC                            gl3wMatrixRotatefEXT;
PFNGLMATRIXSCALEDEXTPROC                             gl3wMatrixScaledEXT;
PFNGLMATRIXSCALEFEXTPROC                             gl3wMatrixScalefEXT;
PFNGLMATRIXTRANSLATEDEXTPROC                         gl3wMatrixTranslatedEXT;
PFNGLMATRIXTRANSLATEFEXTPROC                         gl3wMatrixTranslatefEXT;
PFNGLMAXSHADERCOMPILERTHREADSARBPROC                 gl3wMaxShaderCompilerThreadsARB;
PFNGLMAXSHADERCOMPILERTHREADSKHRPROC                 gl3wMaxShaderCompilerThreadsKHR;
PFNGLMEMORYBARRIERPROC                               gl3wMemoryBarrier;
PFNGLMEMORYBARRIERBYREGIONPROC                       gl3wMemoryBarrierByRegion;
PFNGLMINSAMPLESHADINGPROC                            gl3wMinSampleShading;
PFNGLMINSAMPLESHADINGARBPROC                         gl3wMinSampleShadingARB;
PFNGLMULTIDRAWARRAYSPROC                             gl3wMultiDrawArrays;
PFNGLMULTIDRAWARRAYSINDIRECTPROC                     gl3wMultiDrawArraysIndirect;
PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC      gl3wMultiDrawArraysIndirectBindlessCountNV;
PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC           gl3wMultiDrawArraysIndirectBindlessNV;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC                gl3wMultiDrawArraysIndirectCount;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC             gl3wMultiDrawArraysIndirectCountARB;
PFNGLMULTIDRAWELEMENTSPROC                           gl3wMultiDrawElements;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC                 gl3wMultiDrawElementsBaseVertex;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC                   gl3wMultiDrawElementsIndirect;
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC    gl3wMultiDrawElementsIndirectBindlessCountNV;
PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC         gl3wMultiDrawElementsIndirectBindlessNV;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC              gl3wMultiDrawElementsIndirectCount;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC           gl3wMultiDrawElementsIndirectCountARB;
PFNGLMULTITEXBUFFEREXTPROC                           gl3wMultiTexBufferEXT;
PFNGLMULTITEXCOORDPOINTEREXTPROC                     gl3wMultiTexCoordPointerEXT;
PFNGLMULTITEXENVFEXTPROC                             gl3wMultiTexEnvfEXT;
PFNGLMULTITEXENVFVEXTPROC                            gl3wMultiTexEnvfvEXT;
PFNGLMULTITEXENVIEXTPROC                             gl3wMultiTexEnviEXT;
PFNGLMULTITEXENVIVEXTPROC                            gl3wMultiTexEnvivEXT;
PFNGLMULTITEXGENDEXTPROC                             gl3wMultiTexGendEXT;
PFNGLMULTITEXGENDVEXTPROC                            gl3wMultiTexGendvEXT;
PFNGLMULTITEXGENFEXTPROC                             gl3wMultiTexGenfEXT;
PFNGLMULTITEXGENFVEXTPROC                            gl3wMultiTexGenfvEXT;
PFNGLMULTITEXGENIEXTPROC                             gl3wMultiTexGeniEXT;
PFNGLMULTITEXGENIVEXTPROC                            gl3wMultiTexGenivEXT;
PFNGLMULTITEXIMAGE1DEXTPROC                          gl3wMultiTexImage1DEXT;
PFNGLMULTITEXIMAGE2DEXTPROC                          gl3wMultiTexImage2DEXT;
PFNGLMULTITEXIMAGE3DEXTPROC                          gl3wMultiTexImage3DEXT;
PFNGLMULTITEXPARAMETERIIVEXTPROC                     gl3wMultiTexParameterIivEXT;
PFNGLMULTITEXPARAMETERIUIVEXTPROC                    gl3wMultiTexParameterIuivEXT;
PFNGLMULTITEXPARAMETERFEXTPROC                       gl3wMultiTexParameterfEXT;
PFNGLMULTITEXPARAMETERFVEXTPROC                      gl3wMultiTexParameterfvEXT;
PFNGLMULTITEXPARAMETERIEXTPROC                       gl3wMultiTexParameteriEXT;
PFNGLMULTITEXPARAMETERIVEXTPROC                      gl3wMultiTexParameterivEXT;
PFNGLMULTITEXRENDERBUFFEREXTPROC                     gl3wMultiTexRenderbufferEXT;
PFNGLMULTITEXSUBIMAGE1DEXTPROC                       gl3wMultiTexSubImage1DEXT;
PFNGLMULTITEXSUBIMAGE2DEXTPROC                       gl3wMultiTexSubImage2DEXT;
PFNGLMULTITEXSUBIMAGE3DEXTPROC                       gl3wMultiTexSubImage3DEXT;
PFNGLNAMEDBUFFERDATAPROC                             gl3wNamedBufferData;
PFNGLNAMEDBUFFERDATAEXTPROC                          gl3wNamedBufferDataEXT;
PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC                gl3wNamedBufferPageCommitmentARB;
PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC                gl3wNamedBufferPageCommitmentEXT;
PFNGLNAMEDBUFFERSTORAGEPROC                          gl3wNamedBufferStorage;
PFNGLNAMEDBUFFERSTORAGEEXTPROC                       gl3wNamedBufferStorageEXT;
PFNGLNAMEDBUFFERSUBDATAPROC                          gl3wNamedBufferSubData;
PFNGLNAMEDBUFFERSUBDATAEXTPROC                       gl3wNamedBufferSubDataEXT;
PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC                   gl3wNamedCopyBufferSubDataEXT;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC                  gl3wNamedFramebufferDrawBuffer;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC                 gl3wNamedFramebufferDrawBuffers;
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC                  gl3wNamedFramebufferParameteri;
PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC               gl3wNamedFramebufferParameteriEXT;
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC                  gl3wNamedFramebufferReadBuffer;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC                gl3wNamedFramebufferRenderbuffer;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC             gl3wNamedFramebufferRenderbufferEXT;
PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC        gl3wNamedFramebufferSampleLocationsfvARB;
PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC         gl3wNamedFramebufferSampleLocationsfvNV;
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC                     gl3wNamedFramebufferTexture;
PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC                gl3wNamedFramebufferTexture1DEXT;
PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC                gl3wNamedFramebufferTexture2DEXT;
PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC                gl3wNamedFramebufferTexture3DEXT;
PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC                  gl3wNamedFramebufferTextureEXT;
PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC              gl3wNamedFramebufferTextureFaceEXT;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC                gl3wNamedFramebufferTextureLayer;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC             gl3wNamedFramebufferTextureLayerEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC             gl3wNamedProgramLocalParameter4dEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC            gl3wNamedProgramLocalParameter4dvEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC             gl3wNamedProgramLocalParameter4fEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC            gl3wNamedProgramLocalParameter4fvEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC            gl3wNamedProgramLocalParameterI4iEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC           gl3wNamedProgramLocalParameterI4ivEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC           gl3wNamedProgramLocalParameterI4uiEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC          gl3wNamedProgramLocalParameterI4uivEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC           gl3wNamedProgramLocalParameters4fvEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC          gl3wNamedProgramLocalParametersI4ivEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC         gl3wNamedProgramLocalParametersI4uivEXT;
PFNGLNAMEDPROGRAMSTRINGEXTPROC                       gl3wNamedProgramStringEXT;
PFNGLNAMEDRENDERBUFFERSTORAGEPROC                    gl3wNamedRenderbufferStorage;
PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC                 gl3wNamedRenderbufferStorageEXT;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC         gl3wNamedRenderbufferStorageMultisample;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC gl3wNamedRenderbufferStorageMultisampleCoverageEXT;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC      gl3wNamedRenderbufferStorageMultisampleEXT;
PFNGLNAMEDSTRINGARBPROC                              gl3wNamedStringARB;
PFNGLNORMALFORMATNVPROC                              gl3wNormalFormatNV;
PFNGLOBJECTLABELPROC                                 gl3wObjectLabel;
PFNGLOBJECTPTRLABELPROC                              gl3wObjectPtrLabel;
PFNGLPATCHPARAMETERFVPROC                            gl3wPatchParameterfv;
PFNGLPATCHPARAMETERIPROC                             gl3wPatchParameteri;
PFNGLPATHCOMMANDSNVPROC                              gl3wPathCommandsNV;
PFNGLPATHCOORDSNVPROC                                gl3wPathCoordsNV;
PFNGLPATHCOVERDEPTHFUNCNVPROC                        gl3wPathCoverDepthFuncNV;
PFNGLPATHDASHARRAYNVPROC                             gl3wPathDashArrayNV;
PFNGLPATHGLYPHINDEXARRAYNVPROC                       gl3wPathGlyphIndexArrayNV;
PFNGLPATHGLYPHINDEXRANGENVPROC                       gl3wPathGlyphIndexRangeNV;
PFNGLPATHGLYPHRANGENVPROC                            gl3wPathGlyphRangeNV;
PFNGLPATHGLYPHSNVPROC                                gl3wPathGlyphsNV;
PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC                 gl3wPathMemoryGlyphIndexArrayNV;
PFNGLPATHPARAMETERFNVPROC                            gl3wPathParameterfNV;
PFNGLPATHPARAMETERFVNVPROC                           gl3wPathParameterfvNV;
PFNGLPATHPARAMETERINVPROC                            gl3wPathParameteriNV;
PFNGLPATHPARAMETERIVNVPROC                           gl3wPathParameterivNV;
PFNGLPATHSTENCILDEPTHOFFSETNVPROC                    gl3wPathStencilDepthOffsetNV;
PFNGLPATHSTENCILFUNCNVPROC                           gl3wPathStencilFuncNV;
PFNGLPATHSTRINGNVPROC                                gl3wPathStringNV;
PFNGLPATHSUBCOMMANDSNVPROC                           gl3wPathSubCommandsNV;
PFNGLPATHSUBCOORDSNVPROC                             gl3wPathSubCoordsNV;
PFNGLPAUSETRANSFORMFEEDBACKPROC                      gl3wPauseTransformFeedback;
PFNGLPIXELSTOREFPROC                                 gl3wPixelStoref;
PFNGLPIXELSTOREIPROC                                 gl3wPixelStorei;
PFNGLPOINTALONGPATHNVPROC                            gl3wPointAlongPathNV;
PFNGLPOINTPARAMETERFPROC                             gl3wPointParameterf;
PFNGLPOINTPARAMETERFVPROC                            gl3wPointParameterfv;
PFNGLPOINTPARAMETERIPROC                             gl3wPointParameteri;
PFNGLPOINTPARAMETERIVPROC                            gl3wPointParameteriv;
PFNGLPOINTSIZEPROC                                   gl3wPointSize;
PFNGLPOLYGONMODEPROC                                 gl3wPolygonMode;
PFNGLPOLYGONOFFSETPROC                               gl3wPolygonOffset;
PFNGLPOLYGONOFFSETCLAMPPROC                          gl3wPolygonOffsetClamp;
PFNGLPOLYGONOFFSETCLAMPEXTPROC                       gl3wPolygonOffsetClampEXT;
PFNGLPOPDEBUGGROUPPROC                               gl3wPopDebugGroup;
PFNGLPOPGROUPMARKEREXTPROC                           gl3wPopGroupMarkerEXT;
PFNGLPRIMITIVEBOUNDINGBOXARBPROC                     gl3wPrimitiveBoundingBoxARB;
PFNGLPRIMITIVERESTARTINDEXPROC                       gl3wPrimitiveRestartIndex;
PFNGLPROGRAMBINARYPROC                               gl3wProgramBinary;
PFNGLPROGRAMPARAMETERIPROC                           gl3wProgramParameteri;
PFNGLPROGRAMPARAMETERIARBPROC                        gl3wProgramParameteriARB;
PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC               gl3wProgramPathFragmentInputGenNV;
PFNGLPROGRAMUNIFORM1DPROC                            gl3wProgramUniform1d;
PFNGLPROGRAMUNIFORM1DEXTPROC                         gl3wProgramUniform1dEXT;
PFNGLPROGRAMUNIFORM1DVPROC                           gl3wProgramUniform1dv;
PFNGLPROGRAMUNIFORM1DVEXTPROC                        gl3wProgramUniform1dvEXT;
PFNGLPROGRAMUNIFORM1FPROC                            gl3wProgramUniform1f;
PFNGLPROGRAMUNIFORM1FEXTPROC                         gl3wProgramUniform1fEXT;
PFNGLPROGRAMUNIFORM1FVPROC                           gl3wProgramUniform1fv;
PFNGLPROGRAMUNIFORM1FVEXTPROC                        gl3wProgramUniform1fvEXT;
PFNGLPROGRAMUNIFORM1IPROC                            gl3wProgramUniform1i;
PFNGLPROGRAMUNIFORM1I64ARBPROC                       gl3wProgramUniform1i64ARB;
PFNGLPROGRAMUNIFORM1I64NVPROC                        gl3wProgramUniform1i64NV;
PFNGLPROGRAMUNIFORM1I64VARBPROC                      gl3wProgramUniform1i64vARB;
PFNGLPROGRAMUNIFORM1I64VNVPROC                       gl3wProgramUniform1i64vNV;
PFNGLPROGRAMUNIFORM1IEXTPROC                         gl3wProgramUniform1iEXT;
PFNGLPROGRAMUNIFORM1IVPROC                           gl3wProgramUniform1iv;
PFNGLPROGRAMUNIFORM1IVEXTPROC                        gl3wProgramUniform1ivEXT;
PFNGLPROGRAMUNIFORM1UIPROC                           gl3wProgramUniform1ui;
PFNGLPROGRAMUNIFORM1UI64ARBPROC                      gl3wProgramUniform1ui64ARB;
PFNGLPROGRAMUNIFORM1UI64NVPROC                       gl3wProgramUniform1ui64NV;
PFNGLPROGRAMUNIFORM1UI64VARBPROC                     gl3wProgramUniform1ui64vARB;
PFNGLPROGRAMUNIFORM1UI64VNVPROC                      gl3wProgramUniform1ui64vNV;
PFNGLPROGRAMUNIFORM1UIEXTPROC                        gl3wProgramUniform1uiEXT;
PFNGLPROGRAMUNIFORM1UIVPROC                          gl3wProgramUniform1uiv;
PFNGLPROGRAMUNIFORM1UIVEXTPROC                       gl3wProgramUniform1uivEXT;
PFNGLPROGRAMUNIFORM2DPROC                            gl3wProgramUniform2d;
PFNGLPROGRAMUNIFORM2DEXTPROC                         gl3wProgramUniform2dEXT;
PFNGLPROGRAMUNIFORM2DVPROC                           gl3wProgramUniform2dv;
PFNGLPROGRAMUNIFORM2DVEXTPROC                        gl3wProgramUniform2dvEXT;
PFNGLPROGRAMUNIFORM2FPROC                            gl3wProgramUniform2f;
PFNGLPROGRAMUNIFORM2FEXTPROC                         gl3wProgramUniform2fEXT;
PFNGLPROGRAMUNIFORM2FVPROC                           gl3wProgramUniform2fv;
PFNGLPROGRAMUNIFORM2FVEXTPROC                        gl3wProgramUniform2fvEXT;
PFNGLPROGRAMUNIFORM2IPROC                            gl3wProgramUniform2i;
PFNGLPROGRAMUNIFORM2I64ARBPROC                       gl3wProgramUniform2i64ARB;
PFNGLPROGRAMUNIFORM2I64NVPROC                        gl3wProgramUniform2i64NV;
PFNGLPROGRAMUNIFORM2I64VARBPROC                      gl3wProgramUniform2i64vARB;
PFNGLPROGRAMUNIFORM2I64VNVPROC                       gl3wProgramUniform2i64vNV;
PFNGLPROGRAMUNIFORM2IEXTPROC                         gl3wProgramUniform2iEXT;
PFNGLPROGRAMUNIFORM2IVPROC                           gl3wProgramUniform2iv;
PFNGLPROGRAMUNIFORM2IVEXTPROC                        gl3wProgramUniform2ivEXT;
PFNGLPROGRAMUNIFORM2UIPROC                           gl3wProgramUniform2ui;
PFNGLPROGRAMUNIFORM2UI64ARBPROC                      gl3wProgramUniform2ui64ARB;
PFNGLPROGRAMUNIFORM2UI64NVPROC                       gl3wProgramUniform2ui64NV;
PFNGLPROGRAMUNIFORM2UI64VARBPROC                     gl3wProgramUniform2ui64vARB;
PFNGLPROGRAMUNIFORM2UI64VNVPROC                      gl3wProgramUniform2ui64vNV;
PFNGLPROGRAMUNIFORM2UIEXTPROC                        gl3wProgramUniform2uiEXT;
PFNGLPROGRAMUNIFORM2UIVPROC                          gl3wProgramUniform2uiv;
PFNGLPROGRAMUNIFORM2UIVEXTPROC                       gl3wProgramUniform2uivEXT;
PFNGLPROGRAMUNIFORM3DPROC                            gl3wProgramUniform3d;
PFNGLPROGRAMUNIFORM3DEXTPROC                         gl3wProgramUniform3dEXT;
PFNGLPROGRAMUNIFORM3DVPROC                           gl3wProgramUniform3dv;
PFNGLPROGRAMUNIFORM3DVEXTPROC                        gl3wProgramUniform3dvEXT;
PFNGLPROGRAMUNIFORM3FPROC                            gl3wProgramUniform3f;
PFNGLPROGRAMUNIFORM3FEXTPROC                         gl3wProgramUniform3fEXT;
PFNGLPROGRAMUNIFORM3FVPROC                           gl3wProgramUniform3fv;
PFNGLPROGRAMUNIFORM3FVEXTPROC                        gl3wProgramUniform3fvEXT;
PFNGLPROGRAMUNIFORM3IPROC                            gl3wProgramUniform3i;
PFNGLPROGRAMUNIFORM3I64ARBPROC                       gl3wProgramUniform3i64ARB;
PFNGLPROGRAMUNIFORM3I64NVPROC                        gl3wProgramUniform3i64NV;
PFNGLPROGRAMUNIFORM3I64VARBPROC                      gl3wProgramUniform3i64vARB;
PFNGLPROGRAMUNIFORM3I64VNVPROC                       gl3wProgramUniform3i64vNV;
PFNGLPROGRAMUNIFORM3IEXTPROC                         gl3wProgramUniform3iEXT;
PFNGLPROGRAMUNIFORM3IVPROC                           gl3wProgramUniform3iv;
PFNGLPROGRAMUNIFORM3IVEXTPROC                        gl3wProgramUniform3ivEXT;
PFNGLPROGRAMUNIFORM3UIPROC                           gl3wProgramUniform3ui;
PFNGLPROGRAMUNIFORM3UI64ARBPROC                      gl3wProgramUniform3ui64ARB;
PFNGLPROGRAMUNIFORM3UI64NVPROC                       gl3wProgramUniform3ui64NV;
PFNGLPROGRAMUNIFORM3UI64VARBPROC                     gl3wProgramUniform3ui64vARB;
PFNGLPROGRAMUNIFORM3UI64VNVPROC                      gl3wProgramUniform3ui64vNV;
PFNGLPROGRAMUNIFORM3UIEXTPROC                        gl3wProgramUniform3uiEXT;
PFNGLPROGRAMUNIFORM3UIVPROC                          gl3wProgramUniform3uiv;
PFNGLPROGRAMUNIFORM3UIVEXTPROC                       gl3wProgramUniform3uivEXT;
PFNGLPROGRAMUNIFORM4DPROC                            gl3wProgramUniform4d;
PFNGLPROGRAMUNIFORM4DEXTPROC                         gl3wProgramUniform4dEXT;
PFNGLPROGRAMUNIFORM4DVPROC                           gl3wProgramUniform4dv;
PFNGLPROGRAMUNIFORM4DVEXTPROC                        gl3wProgramUniform4dvEXT;
PFNGLPROGRAMUNIFORM4FPROC                            gl3wProgramUniform4f;
PFNGLPROGRAMUNIFORM4FEXTPROC                         gl3wProgramUniform4fEXT;
PFNGLPROGRAMUNIFORM4FVPROC                           gl3wProgramUniform4fv;
PFNGLPROGRAMUNIFORM4FVEXTPROC                        gl3wProgramUniform4fvEXT;
PFNGLPROGRAMUNIFORM4IPROC                            gl3wProgramUniform4i;
PFNGLPROGRAMUNIFORM4I64ARBPROC                       gl3wProgramUniform4i64ARB;
PFNGLPROGRAMUNIFORM4I64NVPROC                        gl3wProgramUniform4i64NV;
PFNGLPROGRAMUNIFORM4I64VARBPROC                      gl3wProgramUniform4i64vARB;
PFNGLPROGRAMUNIFORM4I64VNVPROC                       gl3wProgramUniform4i64vNV;
PFNGLPROGRAMUNIFORM4IEXTPROC                         gl3wProgramUniform4iEXT;
PFNGLPROGRAMUNIFORM4IVPROC                           gl3wProgramUniform4iv;
PFNGLPROGRAMUNIFORM4IVEXTPROC                        gl3wProgramUniform4ivEXT;
PFNGLPROGRAMUNIFORM4UIPROC                           gl3wProgramUniform4ui;
PFNGLPROGRAMUNIFORM4UI64ARBPROC                      gl3wProgramUniform4ui64ARB;
PFNGLPROGRAMUNIFORM4UI64NVPROC                       gl3wProgramUniform4ui64NV;
PFNGLPROGRAMUNIFORM4UI64VARBPROC                     gl3wProgramUniform4ui64vARB;
PFNGLPROGRAMUNIFORM4UI64VNVPROC                      gl3wProgramUniform4ui64vNV;
PFNGLPROGRAMUNIFORM4UIEXTPROC                        gl3wProgramUniform4uiEXT;
PFNGLPROGRAMUNIFORM4UIVPROC                          gl3wProgramUniform4uiv;
PFNGLPROGRAMUNIFORM4UIVEXTPROC                       gl3wProgramUniform4uivEXT;
PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC                 gl3wProgramUniformHandleui64ARB;
PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC                  gl3wProgramUniformHandleui64NV;
PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC                gl3wProgramUniformHandleui64vARB;
PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC                 gl3wProgramUniformHandleui64vNV;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC                     gl3wProgramUniformMatrix2dv;
PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC                  gl3wProgramUniformMatrix2dvEXT;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC                     gl3wProgramUniformMatrix2fv;
PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC                  gl3wProgramUniformMatrix2fvEXT;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC                   gl3wProgramUniformMatrix2x3dv;
PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC                gl3wProgramUniformMatrix2x3dvEXT;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC                   gl3wProgramUniformMatrix2x3fv;
PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC                gl3wProgramUniformMatrix2x3fvEXT;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC                   gl3wProgramUniformMatrix2x4dv;
PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC                gl3wProgramUniformMatrix2x4dvEXT;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC                   gl3wProgramUniformMatrix2x4fv;
PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC                gl3wProgramUniformMatrix2x4fvEXT;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC                     gl3wProgramUniformMatrix3dv;
PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC                  gl3wProgramUniformMatrix3dvEXT;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC                     gl3wProgramUniformMatrix3fv;
PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC                  gl3wProgramUniformMatrix3fvEXT;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC                   gl3wProgramUniformMatrix3x2dv;
PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC                gl3wProgramUniformMatrix3x2dvEXT;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC                   gl3wProgramUniformMatrix3x2fv;
PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC                gl3wProgramUniformMatrix3x2fvEXT;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC                   gl3wProgramUniformMatrix3x4dv;
PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC                gl3wProgramUniformMatrix3x4dvEXT;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC                   gl3wProgramUniformMatrix3x4fv;
PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC                gl3wProgramUniformMatrix3x4fvEXT;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC                     gl3wProgramUniformMatrix4dv;
PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC                  gl3wProgramUniformMatrix4dvEXT;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC                     gl3wProgramUniformMatrix4fv;
PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC                  gl3wProgramUniformMatrix4fvEXT;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC                   gl3wProgramUniformMatrix4x2dv;
PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC                gl3wProgramUniformMatrix4x2dvEXT;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC                   gl3wProgramUniformMatrix4x2fv;
PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC                gl3wProgramUniformMatrix4x2fvEXT;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC                   gl3wProgramUniformMatrix4x3dv;
PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC                gl3wProgramUniformMatrix4x3dvEXT;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC                   gl3wProgramUniformMatrix4x3fv;
PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC                gl3wProgramUniformMatrix4x3fvEXT;
PFNGLPROGRAMUNIFORMUI64NVPROC                        gl3wProgramUniformui64NV;
PFNGLPROGRAMUNIFORMUI64VNVPROC                       gl3wProgramUniformui64vNV;
PFNGLPROVOKINGVERTEXPROC                             gl3wProvokingVertex;
PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC                  gl3wPushClientAttribDefaultEXT;
PFNGLPUSHDEBUGGROUPPROC                              gl3wPushDebugGroup;
PFNGLPUSHGROUPMARKEREXTPROC                          gl3wPushGroupMarkerEXT;
PFNGLQUERYCOUNTERPROC                                gl3wQueryCounter;
PFNGLRASTERSAMPLESEXTPROC                            gl3wRasterSamplesEXT;
PFNGLREADBUFFERPROC                                  gl3wReadBuffer;
PFNGLREADPIXELSPROC                                  gl3wReadPixels;
PFNGLREADNPIXELSPROC                                 gl3wReadnPixels;
PFNGLREADNPIXELSARBPROC                              gl3wReadnPixelsARB;
PFNGLRELEASESHADERCOMPILERPROC                       gl3wReleaseShaderCompiler;
PFNGLRENDERBUFFERSTORAGEPROC                         gl3wRenderbufferStorage;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC              gl3wRenderbufferStorageMultisample;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC    gl3wRenderbufferStorageMultisampleCoverageNV;
PFNGLRESOLVEDEPTHVALUESNVPROC                        gl3wResolveDepthValuesNV;
PFNGLRESUMETRANSFORMFEEDBACKPROC                     gl3wResumeTransformFeedback;
PFNGLSAMPLECOVERAGEPROC                              gl3wSampleCoverage;
PFNGLSAMPLEMASKIPROC                                 gl3wSampleMaski;
PFNGLSAMPLERPARAMETERIIVPROC                         gl3wSamplerParameterIiv;
PFNGLSAMPLERPARAMETERIUIVPROC                        gl3wSamplerParameterIuiv;
PFNGLSAMPLERPARAMETERFPROC                           gl3wSamplerParameterf;
PFNGLSAMPLERPARAMETERFVPROC                          gl3wSamplerParameterfv;
PFNGLSAMPLERPARAMETERIPROC                           gl3wSamplerParameteri;
PFNGLSAMPLERPARAMETERIVPROC                          gl3wSamplerParameteriv;
PFNGLSCISSORPROC                                     gl3wScissor;
PFNGLSCISSORARRAYVPROC                               gl3wScissorArrayv;
PFNGLSCISSORINDEXEDPROC                              gl3wScissorIndexed;
PFNGLSCISSORINDEXEDVPROC                             gl3wScissorIndexedv;
PFNGLSECONDARYCOLORFORMATNVPROC                      gl3wSecondaryColorFormatNV;
PFNGLSELECTPERFMONITORCOUNTERSAMDPROC                gl3wSelectPerfMonitorCountersAMD;
PFNGLSHADERBINARYPROC                                gl3wShaderBinary;
PFNGLSHADERSOURCEPROC                                gl3wShaderSource;
PFNGLSHADERSTORAGEBLOCKBINDINGPROC                   gl3wShaderStorageBlockBinding;
PFNGLSIGNALVKFENCENVPROC                             gl3wSignalVkFenceNV;
PFNGLSIGNALVKSEMAPHORENVPROC                         gl3wSignalVkSemaphoreNV;
PFNGLSPECIALIZESHADERPROC                            gl3wSpecializeShader;
PFNGLSPECIALIZESHADERARBPROC                         gl3wSpecializeShaderARB;
PFNGLSTATECAPTURENVPROC                              gl3wStateCaptureNV;
PFNGLSTENCILFILLPATHINSTANCEDNVPROC                  gl3wStencilFillPathInstancedNV;
PFNGLSTENCILFILLPATHNVPROC                           gl3wStencilFillPathNV;
PFNGLSTENCILFUNCPROC                                 gl3wStencilFunc;
PFNGLSTENCILFUNCSEPARATEPROC                         gl3wStencilFuncSeparate;
PFNGLSTENCILMASKPROC                                 gl3wStencilMask;
PFNGLSTENCILMASKSEPARATEPROC                         gl3wStencilMaskSeparate;
PFNGLSTENCILOPPROC                                   gl3wStencilOp;
PFNGLSTENCILOPSEPARATEPROC                           gl3wStencilOpSeparate;
PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC                gl3wStencilStrokePathInstancedNV;
PFNGLSTENCILSTROKEPATHNVPROC                         gl3wStencilStrokePathNV;
PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC         gl3wStencilThenCoverFillPathInstancedNV;
PFNGLSTENCILTHENCOVERFILLPATHNVPROC                  gl3wStencilThenCoverFillPathNV;
PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC       gl3wStencilThenCoverStrokePathInstancedNV;
PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC                gl3wStencilThenCoverStrokePathNV;
PFNGLSUBPIXELPRECISIONBIASNVPROC                     gl3wSubpixelPrecisionBiasNV;
PFNGLTEXBUFFERPROC                                   gl3wTexBuffer;
PFNGLTEXBUFFERARBPROC                                gl3wTexBufferARB;
PFNGLTEXBUFFERRANGEPROC                              gl3wTexBufferRange;
PFNGLTEXCOORDFORMATNVPROC                            gl3wTexCoordFormatNV;
PFNGLTEXIMAGE1DPROC                                  gl3wTexImage1D;
PFNGLTEXIMAGE2DPROC                                  gl3wTexImage2D;
PFNGLTEXIMAGE2DMULTISAMPLEPROC                       gl3wTexImage2DMultisample;
PFNGLTEXIMAGE3DPROC                                  gl3wTexImage3D;
PFNGLTEXIMAGE3DMULTISAMPLEPROC                       gl3wTexImage3DMultisample;
PFNGLTEXPAGECOMMITMENTARBPROC                        gl3wTexPageCommitmentARB;
PFNGLTEXPARAMETERIIVPROC                             gl3wTexParameterIiv;
PFNGLTEXPARAMETERIUIVPROC                            gl3wTexParameterIuiv;
PFNGLTEXPARAMETERFPROC                               gl3wTexParameterf;
PFNGLTEXPARAMETERFVPROC                              gl3wTexParameterfv;
PFNGLTEXPARAMETERIPROC                               gl3wTexParameteri;
PFNGLTEXPARAMETERIVPROC                              gl3wTexParameteriv;
PFNGLTEXSTORAGE1DPROC                                gl3wTexStorage1D;
PFNGLTEXSTORAGE2DPROC                                gl3wTexStorage2D;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC                     gl3wTexStorage2DMultisample;
PFNGLTEXSTORAGE3DPROC                                gl3wTexStorage3D;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC                     gl3wTexStorage3DMultisample;
PFNGLTEXSUBIMAGE1DPROC                               gl3wTexSubImage1D;
PFNGLTEXSUBIMAGE2DPROC                               gl3wTexSubImage2D;
PFNGLTEXSUBIMAGE3DPROC                               gl3wTexSubImage3D;
PFNGLTEXTUREBARRIERPROC                              gl3wTextureBarrier;
PFNGLTEXTUREBARRIERNVPROC                            gl3wTextureBarrierNV;
PFNGLTEXTUREBUFFERPROC                               gl3wTextureBuffer;
PFNGLTEXTUREBUFFEREXTPROC                            gl3wTextureBufferEXT;
PFNGLTEXTUREBUFFERRANGEPROC                          gl3wTextureBufferRange;
PFNGLTEXTUREBUFFERRANGEEXTPROC                       gl3wTextureBufferRangeEXT;
PFNGLTEXTUREIMAGE1DEXTPROC                           gl3wTextureImage1DEXT;
PFNGLTEXTUREIMAGE2DEXTPROC                           gl3wTextureImage2DEXT;
PFNGLTEXTUREIMAGE3DEXTPROC                           gl3wTextureImage3DEXT;
PFNGLTEXTUREPAGECOMMITMENTEXTPROC                    gl3wTexturePageCommitmentEXT;
PFNGLTEXTUREPARAMETERIIVPROC                         gl3wTextureParameterIiv;
PFNGLTEXTUREPARAMETERIIVEXTPROC                      gl3wTextureParameterIivEXT;
PFNGLTEXTUREPARAMETERIUIVPROC                        gl3wTextureParameterIuiv;
PFNGLTEXTUREPARAMETERIUIVEXTPROC                     gl3wTextureParameterIuivEXT;
PFNGLTEXTUREPARAMETERFPROC                           gl3wTextureParameterf;
PFNGLTEXTUREPARAMETERFEXTPROC                        gl3wTextureParameterfEXT;
PFNGLTEXTUREPARAMETERFVPROC                          gl3wTextureParameterfv;
PFNGLTEXTUREPARAMETERFVEXTPROC                       gl3wTextureParameterfvEXT;
PFNGLTEXTUREPARAMETERIPROC                           gl3wTextureParameteri;
PFNGLTEXTUREPARAMETERIEXTPROC                        gl3wTextureParameteriEXT;
PFNGLTEXTUREPARAMETERIVPROC                          gl3wTextureParameteriv;
PFNGLTEXTUREPARAMETERIVEXTPROC                       gl3wTextureParameterivEXT;
PFNGLTEXTURERENDERBUFFEREXTPROC                      gl3wTextureRenderbufferEXT;
PFNGLTEXTURESTORAGE1DPROC                            gl3wTextureStorage1D;
PFNGLTEXTURESTORAGE1DEXTPROC                         gl3wTextureStorage1DEXT;
PFNGLTEXTURESTORAGE2DPROC                            gl3wTextureStorage2D;
PFNGLTEXTURESTORAGE2DEXTPROC                         gl3wTextureStorage2DEXT;
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC                 gl3wTextureStorage2DMultisample;
PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC              gl3wTextureStorage2DMultisampleEXT;
PFNGLTEXTURESTORAGE3DPROC                            gl3wTextureStorage3D;
PFNGLTEXTURESTORAGE3DEXTPROC                         gl3wTextureStorage3DEXT;
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC                 gl3wTextureStorage3DMultisample;
PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC              gl3wTextureStorage3DMultisampleEXT;
PFNGLTEXTURESUBIMAGE1DPROC                           gl3wTextureSubImage1D;
PFNGLTEXTURESUBIMAGE1DEXTPROC                        gl3wTextureSubImage1DEXT;
PFNGLTEXTURESUBIMAGE2DPROC                           gl3wTextureSubImage2D;
PFNGLTEXTURESUBIMAGE2DEXTPROC                        gl3wTextureSubImage2DEXT;
PFNGLTEXTURESUBIMAGE3DPROC                           gl3wTextureSubImage3D;
PFNGLTEXTURESUBIMAGE3DEXTPROC                        gl3wTextureSubImage3DEXT;
PFNGLTEXTUREVIEWPROC                                 gl3wTextureView;
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC                 gl3wTransformFeedbackBufferBase;
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC                gl3wTransformFeedbackBufferRange;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC                   gl3wTransformFeedbackVaryings;
PFNGLTRANSFORMPATHNVPROC                             gl3wTransformPathNV;
PFNGLUNIFORM1DPROC                                   gl3wUniform1d;
PFNGLUNIFORM1DVPROC                                  gl3wUniform1dv;
PFNGLUNIFORM1FPROC                                   gl3wUniform1f;
PFNGLUNIFORM1FVPROC                                  gl3wUniform1fv;
PFNGLUNIFORM1IPROC                                   gl3wUniform1i;
PFNGLUNIFORM1I64ARBPROC                              gl3wUniform1i64ARB;
PFNGLUNIFORM1I64NVPROC                               gl3wUniform1i64NV;
PFNGLUNIFORM1I64VARBPROC                             gl3wUniform1i64vARB;
PFNGLUNIFORM1I64VNVPROC                              gl3wUniform1i64vNV;
PFNGLUNIFORM1IVPROC                                  gl3wUniform1iv;
PFNGLUNIFORM1UIPROC                                  gl3wUniform1ui;
PFNGLUNIFORM1UI64ARBPROC                             gl3wUniform1ui64ARB;
PFNGLUNIFORM1UI64NVPROC                              gl3wUniform1ui64NV;
PFNGLUNIFORM1UI64VARBPROC                            gl3wUniform1ui64vARB;
PFNGLUNIFORM1UI64VNVPROC                             gl3wUniform1ui64vNV;
PFNGLUNIFORM1UIVPROC                                 gl3wUniform1uiv;
PFNGLUNIFORM2DPROC                                   gl3wUniform2d;
PFNGLUNIFORM2DVPROC                                  gl3wUniform2dv;
PFNGLUNIFORM2FPROC                                   gl3wUniform2f;
PFNGLUNIFORM2FVPROC                                  gl3wUniform2fv;
PFNGLUNIFORM2IPROC                                   gl3wUniform2i;
PFNGLUNIFORM2I64ARBPROC                              gl3wUniform2i64ARB;
PFNGLUNIFORM2I64NVPROC                               gl3wUniform2i64NV;
PFNGLUNIFORM2I64VARBPROC                             gl3wUniform2i64vARB;
PFNGLUNIFORM2I64VNVPROC                              gl3wUniform2i64vNV;
PFNGLUNIFORM2IVPROC                                  gl3wUniform2iv;
PFNGLUNIFORM2UIPROC                                  gl3wUniform2ui;
PFNGLUNIFORM2UI64ARBPROC                             gl3wUniform2ui64ARB;
PFNGLUNIFORM2UI64NVPROC                              gl3wUniform2ui64NV;
PFNGLUNIFORM2UI64VARBPROC                            gl3wUniform2ui64vARB;
PFNGLUNIFORM2UI64VNVPROC                             gl3wUniform2ui64vNV;
PFNGLUNIFORM2UIVPROC                                 gl3wUniform2uiv;
PFNGLUNIFORM3DPROC                                   gl3wUniform3d;
PFNGLUNIFORM3DVPROC                                  gl3wUniform3dv;
PFNGLUNIFORM3FPROC                                   gl3wUniform3f;
PFNGLUNIFORM3FVPROC                                  gl3wUniform3fv;
PFNGLUNIFORM3IPROC                                   gl3wUniform3i;
PFNGLUNIFORM3I64ARBPROC                              gl3wUniform3i64ARB;
PFNGLUNIFORM3I64NVPROC                               gl3wUniform3i64NV;
PFNGLUNIFORM3I64VARBPROC                             gl3wUniform3i64vARB;
PFNGLUNIFORM3I64VNVPROC                              gl3wUniform3i64vNV;
PFNGLUNIFORM3IVPROC                                  gl3wUniform3iv;
PFNGLUNIFORM3UIPROC                                  gl3wUniform3ui;
PFNGLUNIFORM3UI64ARBPROC                             gl3wUniform3ui64ARB;
PFNGLUNIFORM3UI64NVPROC                              gl3wUniform3ui64NV;
PFNGLUNIFORM3UI64VARBPROC                            gl3wUniform3ui64vARB;
PFNGLUNIFORM3UI64VNVPROC                             gl3wUniform3ui64vNV;
PFNGLUNIFORM3UIVPROC                                 gl3wUniform3uiv;
PFNGLUNIFORM4DPROC                                   gl3wUniform4d;
PFNGLUNIFORM4DVPROC                                  gl3wUniform4dv;
PFNGLUNIFORM4FPROC                                   gl3wUniform4f;
PFNGLUNIFORM4FVPROC                                  gl3wUniform4fv;
PFNGLUNIFORM4IPROC                                   gl3wUniform4i;
PFNGLUNIFORM4I64ARBPROC                              gl3wUniform4i64ARB;
PFNGLUNIFORM4I64NVPROC                               gl3wUniform4i64NV;
PFNGLUNIFORM4I64VARBPROC                             gl3wUniform4i64vARB;
PFNGLUNIFORM4I64VNVPROC                              gl3wUniform4i64vNV;
PFNGLUNIFORM4IVPROC                                  gl3wUniform4iv;
PFNGLUNIFORM4UIPROC                                  gl3wUniform4ui;
PFNGLUNIFORM4UI64ARBPROC                             gl3wUniform4ui64ARB;
PFNGLUNIFORM4UI64NVPROC                              gl3wUniform4ui64NV;
PFNGLUNIFORM4UI64VARBPROC                            gl3wUniform4ui64vARB;
PFNGLUNIFORM4UI64VNVPROC                             gl3wUniform4ui64vNV;
PFNGLUNIFORM4UIVPROC                                 gl3wUniform4uiv;
PFNGLUNIFORMBLOCKBINDINGPROC                         gl3wUniformBlockBinding;
PFNGLUNIFORMHANDLEUI64ARBPROC                        gl3wUniformHandleui64ARB;
PFNGLUNIFORMHANDLEUI64NVPROC                         gl3wUniformHandleui64NV;
PFNGLUNIFORMHANDLEUI64VARBPROC                       gl3wUniformHandleui64vARB;
PFNGLUNIFORMHANDLEUI64VNVPROC                        gl3wUniformHandleui64vNV;
PFNGLUNIFORMMATRIX2DVPROC                            gl3wUniformMatrix2dv;
PFNGLUNIFORMMATRIX2FVPROC                            gl3wUniformMatrix2fv;
PFNGLUNIFORMMATRIX2X3DVPROC                          gl3wUniformMatrix2x3dv;
PFNGLUNIFORMMATRIX2X3FVPROC                          gl3wUniformMatrix2x3fv;
PFNGLUNIFORMMATRIX2X4DVPROC                          gl3wUniformMatrix2x4dv;
PFNGLUNIFORMMATRIX2X4FVPROC                          gl3wUniformMatrix2x4fv;
PFNGLUNIFORMMATRIX3DVPROC                            gl3wUniformMatrix3dv;
PFNGLUNIFORMMATRIX3FVPROC                            gl3wUniformMatrix3fv;
PFNGLUNIFORMMATRIX3X2DVPROC                          gl3wUniformMatrix3x2dv;
PFNGLUNIFORMMATRIX3X2FVPROC                          gl3wUniformMatrix3x2fv;
PFNGLUNIFORMMATRIX3X4DVPROC                          gl3wUniformMatrix3x4dv;
PFNGLUNIFORMMATRIX3X4FVPROC                          gl3wUniformMatrix3x4fv;
PFNGLUNIFORMMATRIX4DVPROC                            gl3wUniformMatrix4dv;
PFNGLUNIFORMMATRIX4FVPROC                            gl3wUniformMatrix4fv;
PFNGLUNIFORMMATRIX4X2DVPROC                          gl3wUniformMatrix4x2dv;
PFNGLUNIFORMMATRIX4X2FVPROC                          gl3wUniformMatrix4x2fv;
PFNGLUNIFORMMATRIX4X3DVPROC                          gl3wUniformMatrix4x3dv;
PFNGLUNIFORMMATRIX4X3FVPROC                          gl3wUniformMatrix4x3fv;
PFNGLUNIFORMSUBROUTINESUIVPROC                       gl3wUniformSubroutinesuiv;
PFNGLUNIFORMUI64NVPROC                               gl3wUniformui64NV;
PFNGLUNIFORMUI64VNVPROC                              gl3wUniformui64vNV;
PFNGLUNMAPBUFFERPROC                                 gl3wUnmapBuffer;
PFNGLUNMAPNAMEDBUFFERPROC                            gl3wUnmapNamedBuffer;
PFNGLUNMAPNAMEDBUFFEREXTPROC                         gl3wUnmapNamedBufferEXT;
PFNGLUSEPROGRAMPROC                                  gl3wUseProgram;
PFNGLUSEPROGRAMSTAGESPROC                            gl3wUseProgramStages;
PFNGLUSESHADERPROGRAMEXTPROC                         gl3wUseShaderProgramEXT;
PFNGLVALIDATEPROGRAMPROC                             gl3wValidateProgram;
PFNGLVALIDATEPROGRAMPIPELINEPROC                     gl3wValidateProgramPipeline;
PFNGLVERTEXARRAYATTRIBBINDINGPROC                    gl3wVertexArrayAttribBinding;
PFNGLVERTEXARRAYATTRIBFORMATPROC                     gl3wVertexArrayAttribFormat;
PFNGLVERTEXARRAYATTRIBIFORMATPROC                    gl3wVertexArrayAttribIFormat;
PFNGLVERTEXARRAYATTRIBLFORMATPROC                    gl3wVertexArrayAttribLFormat;
PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC              gl3wVertexArrayBindVertexBufferEXT;
PFNGLVERTEXARRAYBINDINGDIVISORPROC                   gl3wVertexArrayBindingDivisor;
PFNGLVERTEXARRAYCOLOROFFSETEXTPROC                   gl3wVertexArrayColorOffsetEXT;
PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC                gl3wVertexArrayEdgeFlagOffsetEXT;
PFNGLVERTEXARRAYELEMENTBUFFERPROC                    gl3wVertexArrayElementBuffer;
PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC                gl3wVertexArrayFogCoordOffsetEXT;
PFNGLVERTEXARRAYINDEXOFFSETEXTPROC                   gl3wVertexArrayIndexOffsetEXT;
PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC           gl3wVertexArrayMultiTexCoordOffsetEXT;
PFNGLVERTEXARRAYNORMALOFFSETEXTPROC                  gl3wVertexArrayNormalOffsetEXT;
PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC          gl3wVertexArraySecondaryColorOffsetEXT;
PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC                gl3wVertexArrayTexCoordOffsetEXT;
PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC           gl3wVertexArrayVertexAttribBindingEXT;
PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC           gl3wVertexArrayVertexAttribDivisorEXT;
PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC            gl3wVertexArrayVertexAttribFormatEXT;
PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC           gl3wVertexArrayVertexAttribIFormatEXT;
PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC           gl3wVertexArrayVertexAttribIOffsetEXT;
PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC           gl3wVertexArrayVertexAttribLFormatEXT;
PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC           gl3wVertexArrayVertexAttribLOffsetEXT;
PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC            gl3wVertexArrayVertexAttribOffsetEXT;
PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC          gl3wVertexArrayVertexBindingDivisorEXT;
PFNGLVERTEXARRAYVERTEXBUFFERPROC                     gl3wVertexArrayVertexBuffer;
PFNGLVERTEXARRAYVERTEXBUFFERSPROC                    gl3wVertexArrayVertexBuffers;
PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC                  gl3wVertexArrayVertexOffsetEXT;
PFNGLVERTEXATTRIB1DPROC                              gl3wVertexAttrib1d;
PFNGLVERTEXATTRIB1DVPROC                             gl3wVertexAttrib1dv;
PFNGLVERTEXATTRIB1FPROC                              gl3wVertexAttrib1f;
PFNGLVERTEXATTRIB1FVPROC                             gl3wVertexAttrib1fv;
PFNGLVERTEXATTRIB1SPROC                              gl3wVertexAttrib1s;
PFNGLVERTEXATTRIB1SVPROC                             gl3wVertexAttrib1sv;
PFNGLVERTEXATTRIB2DPROC                              gl3wVertexAttrib2d;
PFNGLVERTEXATTRIB2DVPROC                             gl3wVertexAttrib2dv;
PFNGLVERTEXATTRIB2FPROC                              gl3wVertexAttrib2f;
PFNGLVERTEXATTRIB2FVPROC                             gl3wVertexAttrib2fv;
PFNGLVERTEXATTRIB2SPROC                              gl3wVertexAttrib2s;
PFNGLVERTEXATTRIB2SVPROC                             gl3wVertexAttrib2sv;
PFNGLVERTEXATTRIB3DPROC                              gl3wVertexAttrib3d;
PFNGLVERTEXATTRIB3DVPROC                             gl3wVertexAttrib3dv;
PFNGLVERTEXATTRIB3FPROC                              gl3wVertexAttrib3f;
PFNGLVERTEXATTRIB3FVPROC                             gl3wVertexAttrib3fv;
PFNGLVERTEXATTRIB3SPROC                              gl3wVertexAttrib3s;
PFNGLVERTEXATTRIB3SVPROC                             gl3wVertexAttrib3sv;
PFNGLVERTEXATTRIB4NBVPROC                            gl3wVertexAttrib4Nbv;
PFNGLVERTEXATTRIB4NIVPROC                            gl3wVertexAttrib4Niv;
PFNGLVERTEXATTRIB4NSVPROC                            gl3wVertexAttrib4Nsv;
PFNGLVERTEXATTRIB4NUBPROC                            gl3wVertexAttrib4Nub;
PFNGLVERTEXATTRIB4NUBVPROC                           gl3wVertexAttrib4Nubv;
PFNGLVERTEXATTRIB4NUIVPROC                           gl3wVertexAttrib4Nuiv;
PFNGLVERTEXATTRIB4NUSVPROC                           gl3wVertexAttrib4Nusv;
PFNGLVERTEXATTRIB4BVPROC                             gl3wVertexAttrib4bv;
PFNGLVERTEXATTRIB4DPROC                              gl3wVertexAttrib4d;
PFNGLVERTEXATTRIB4DVPROC                             gl3wVertexAttrib4dv;
PFNGLVERTEXATTRIB4FPROC                              gl3wVertexAttrib4f;
PFNGLVERTEXATTRIB4FVPROC                             gl3wVertexAttrib4fv;
PFNGLVERTEXATTRIB4IVPROC                             gl3wVertexAttrib4iv;
PFNGLVERTEXATTRIB4SPROC                              gl3wVertexAttrib4s;
PFNGLVERTEXATTRIB4SVPROC                             gl3wVertexAttrib4sv;
PFNGLVERTEXATTRIB4UBVPROC                            gl3wVertexAttrib4ubv;
PFNGLVERTEXATTRIB4UIVPROC                            gl3wVertexAttrib4uiv;
PFNGLVERTEXATTRIB4USVPROC                            gl3wVertexAttrib4usv;
PFNGLVERTEXATTRIBBINDINGPROC                         gl3wVertexAttribBinding;
PFNGLVERTEXATTRIBDIVISORPROC                         gl3wVertexAttribDivisor;
PFNGLVERTEXATTRIBDIVISORARBPROC                      gl3wVertexAttribDivisorARB;
PFNGLVERTEXATTRIBFORMATPROC                          gl3wVertexAttribFormat;
PFNGLVERTEXATTRIBFORMATNVPROC                        gl3wVertexAttribFormatNV;
PFNGLVERTEXATTRIBI1IPROC                             gl3wVertexAttribI1i;
PFNGLVERTEXATTRIBI1IVPROC                            gl3wVertexAttribI1iv;
PFNGLVERTEXATTRIBI1UIPROC                            gl3wVertexAttribI1ui;
PFNGLVERTEXATTRIBI1UIVPROC                           gl3wVertexAttribI1uiv;
PFNGLVERTEXATTRIBI2IPROC                             gl3wVertexAttribI2i;
PFNGLVERTEXATTRIBI2IVPROC                            gl3wVertexAttribI2iv;
PFNGLVERTEXATTRIBI2UIPROC                            gl3wVertexAttribI2ui;
PFNGLVERTEXATTRIBI2UIVPROC                           gl3wVertexAttribI2uiv;
PFNGLVERTEXATTRIBI3IPROC                             gl3wVertexAttribI3i;
PFNGLVERTEXATTRIBI3IVPROC                            gl3wVertexAttribI3iv;
PFNGLVERTEXATTRIBI3UIPROC                            gl3wVertexAttribI3ui;
PFNGLVERTEXATTRIBI3UIVPROC                           gl3wVertexAttribI3uiv;
PFNGLVERTEXATTRIBI4BVPROC                            gl3wVertexAttribI4bv;
PFNGLVERTEXATTRIBI4IPROC                             gl3wVertexAttribI4i;
PFNGLVERTEXATTRIBI4IVPROC                            gl3wVertexAttribI4iv;
PFNGLVERTEXATTRIBI4SVPROC                            gl3wVertexAttribI4sv;
PFNGLVERTEXATTRIBI4UBVPROC                           gl3wVertexAttribI4ubv;
PFNGLVERTEXATTRIBI4UIPROC                            gl3wVertexAttribI4ui;
PFNGLVERTEXATTRIBI4UIVPROC                           gl3wVertexAttribI4uiv;
PFNGLVERTEXATTRIBI4USVPROC                           gl3wVertexAttribI4usv;
PFNGLVERTEXATTRIBIFORMATPROC                         gl3wVertexAttribIFormat;
PFNGLVERTEXATTRIBIFORMATNVPROC                       gl3wVertexAttribIFormatNV;
PFNGLVERTEXATTRIBIPOINTERPROC                        gl3wVertexAttribIPointer;
PFNGLVERTEXATTRIBL1DPROC                             gl3wVertexAttribL1d;
PFNGLVERTEXATTRIBL1DVPROC                            gl3wVertexAttribL1dv;
PFNGLVERTEXATTRIBL1I64NVPROC                         gl3wVertexAttribL1i64NV;
PFNGLVERTEXATTRIBL1I64VNVPROC                        gl3wVertexAttribL1i64vNV;
PFNGLVERTEXATTRIBL1UI64ARBPROC                       gl3wVertexAttribL1ui64ARB;
PFNGLVERTEXATTRIBL1UI64NVPROC                        gl3wVertexAttribL1ui64NV;
PFNGLVERTEXATTRIBL1UI64VARBPROC                      gl3wVertexAttribL1ui64vARB;
PFNGLVERTEXATTRIBL1UI64VNVPROC                       gl3wVertexAttribL1ui64vNV;
PFNGLVERTEXATTRIBL2DPROC                             gl3wVertexAttribL2d;
PFNGLVERTEXATTRIBL2DVPROC                            gl3wVertexAttribL2dv;
PFNGLVERTEXATTRIBL2I64NVPROC                         gl3wVertexAttribL2i64NV;
PFNGLVERTEXATTRIBL2I64VNVPROC                        gl3wVertexAttribL2i64vNV;
PFNGLVERTEXATTRIBL2UI64NVPROC                        gl3wVertexAttribL2ui64NV;
PFNGLVERTEXATTRIBL2UI64VNVPROC                       gl3wVertexAttribL2ui64vNV;
PFNGLVERTEXATTRIBL3DPROC                             gl3wVertexAttribL3d;
PFNGLVERTEXATTRIBL3DVPROC                            gl3wVertexAttribL3dv;
PFNGLVERTEXATTRIBL3I64NVPROC                         gl3wVertexAttribL3i64NV;
PFNGLVERTEXATTRIBL3I64VNVPROC                        gl3wVertexAttribL3i64vNV;
PFNGLVERTEXATTRIBL3UI64NVPROC                        gl3wVertexAttribL3ui64NV;
PFNGLVERTEXATTRIBL3UI64VNVPROC                       gl3wVertexAttribL3ui64vNV;
PFNGLVERTEXATTRIBL4DPROC                             gl3wVertexAttribL4d;
PFNGLVERTEXATTRIBL4DVPROC                            gl3wVertexAttribL4dv;
PFNGLVERTEXATTRIBL4I64NVPROC                         gl3wVertexAttribL4i64NV;
PFNGLVERTEXATTRIBL4I64VNVPROC                        gl3wVertexAttribL4i64vNV;
PFNGLVERTEXATTRIBL4UI64NVPROC                        gl3wVertexAttribL4ui64NV;
PFNGLVERTEXATTRIBL4UI64VNVPROC                       gl3wVertexAttribL4ui64vNV;
PFNGLVERTEXATTRIBLFORMATPROC                         gl3wVertexAttribLFormat;
PFNGLVERTEXATTRIBLFORMATNVPROC                       gl3wVertexAttribLFormatNV;
PFNGLVERTEXATTRIBLPOINTERPROC                        gl3wVertexAttribLPointer;
PFNGLVERTEXATTRIBP1UIPROC                            gl3wVertexAttribP1ui;
PFNGLVERTEXATTRIBP1UIVPROC                           gl3wVertexAttribP1uiv;
PFNGLVERTEXATTRIBP2UIPROC                            gl3wVertexAttribP2ui;
PFNGLVERTEXATTRIBP2UIVPROC                           gl3wVertexAttribP2uiv;
PFNGLVERTEXATTRIBP3UIPROC                            gl3wVertexAttribP3ui;
PFNGLVERTEXATTRIBP3UIVPROC                           gl3wVertexAttribP3uiv;
PFNGLVERTEXATTRIBP4UIPROC                            gl3wVertexAttribP4ui;
PFNGLVERTEXATTRIBP4UIVPROC                           gl3wVertexAttribP4uiv;
PFNGLVERTEXATTRIBPOINTERPROC                         gl3wVertexAttribPointer;
PFNGLVERTEXBINDINGDIVISORPROC                        gl3wVertexBindingDivisor;
PFNGLVERTEXFORMATNVPROC                              gl3wVertexFormatNV;
PFNGLVIEWPORTPROC                                    gl3wViewport;
PFNGLVIEWPORTARRAYVPROC                              gl3wViewportArrayv;
PFNGLVIEWPORTINDEXEDFPROC                            gl3wViewportIndexedf;
PFNGLVIEWPORTINDEXEDFVPROC                           gl3wViewportIndexedfv;
PFNGLVIEWPORTPOSITIONWSCALENVPROC                    gl3wViewportPositionWScaleNV;
PFNGLVIEWPORTSWIZZLENVPROC                           gl3wViewportSwizzleNV;
PFNGLWAITSYNCPROC                                    gl3wWaitSync;
PFNGLWAITVKSEMAPHORENVPROC                           gl3wWaitVkSemaphoreNV;
PFNGLWEIGHTPATHSNVPROC                               gl3wWeightPathsNV;
PFNGLWINDOWRECTANGLESEXTPROC                         gl3wWindowRectanglesEXT;

static void gl3w__load_procs(void)
{
	gl3wActiveProgramEXT = (PFNGLACTIVEPROGRAMEXTPROC) gl3w__get_proc("glActiveProgramEXT");
	gl3wActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC) gl3w__get_proc("glActiveShaderProgram");
	gl3wActiveTexture = (PFNGLACTIVETEXTUREPROC) gl3w__get_proc("glActiveTexture");
	gl3wApplyFramebufferAttachmentCMAAINTEL = (PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC) gl3w__get_proc("glApplyFramebufferAttachmentCMAAINTEL");
	gl3wAttachShader = (PFNGLATTACHSHADERPROC) gl3w__get_proc("glAttachShader");
	gl3wBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC) gl3w__get_proc("glBeginConditionalRender");
	gl3wBeginConditionalRenderNV = (PFNGLBEGINCONDITIONALRENDERNVPROC) gl3w__get_proc("glBeginConditionalRenderNV");
	gl3wBeginPerfMonitorAMD = (PFNGLBEGINPERFMONITORAMDPROC) gl3w__get_proc("glBeginPerfMonitorAMD");
	gl3wBeginPerfQueryINTEL = (PFNGLBEGINPERFQUERYINTELPROC) gl3w__get_proc("glBeginPerfQueryINTEL");
	gl3wBeginQuery = (PFNGLBEGINQUERYPROC) gl3w__get_proc("glBeginQuery");
	gl3wBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC) gl3w__get_proc("glBeginQueryIndexed");
	gl3wBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC) gl3w__get_proc("glBeginTransformFeedback");
	gl3wBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) gl3w__get_proc("glBindAttribLocation");
	gl3wBindBuffer = (PFNGLBINDBUFFERPROC) gl3w__get_proc("glBindBuffer");
	gl3wBindBufferBase = (PFNGLBINDBUFFERBASEPROC) gl3w__get_proc("glBindBufferBase");
	gl3wBindBufferRange = (PFNGLBINDBUFFERRANGEPROC) gl3w__get_proc("glBindBufferRange");
	gl3wBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC) gl3w__get_proc("glBindBuffersBase");
	gl3wBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC) gl3w__get_proc("glBindBuffersRange");
	gl3wBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC) gl3w__get_proc("glBindFragDataLocation");
	gl3wBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) gl3w__get_proc("glBindFragDataLocationIndexed");
	gl3wBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC) gl3w__get_proc("glBindFramebuffer");
	gl3wBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC) gl3w__get_proc("glBindImageTexture");
	gl3wBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC) gl3w__get_proc("glBindImageTextures");
	gl3wBindMultiTextureEXT = (PFNGLBINDMULTITEXTUREEXTPROC) gl3w__get_proc("glBindMultiTextureEXT");
	gl3wBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC) gl3w__get_proc("glBindProgramPipeline");
	gl3wBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC) gl3w__get_proc("glBindRenderbuffer");
	gl3wBindSampler = (PFNGLBINDSAMPLERPROC) gl3w__get_proc("glBindSampler");
	gl3wBindSamplers = (PFNGLBINDSAMPLERSPROC) gl3w__get_proc("glBindSamplers");
	gl3wBindTexture = (PFNGLBINDTEXTUREPROC) gl3w__get_proc("glBindTexture");
	gl3wBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC) gl3w__get_proc("glBindTextureUnit");
	gl3wBindTextures = (PFNGLBINDTEXTURESPROC) gl3w__get_proc("glBindTextures");
	gl3wBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC) gl3w__get_proc("glBindTransformFeedback");
	gl3wBindVertexArray = (PFNGLBINDVERTEXARRAYPROC) gl3w__get_proc("glBindVertexArray");
	gl3wBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC) gl3w__get_proc("glBindVertexBuffer");
	gl3wBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC) gl3w__get_proc("glBindVertexBuffers");
	gl3wBlendBarrierKHR = (PFNGLBLENDBARRIERKHRPROC) gl3w__get_proc("glBlendBarrierKHR");
	gl3wBlendBarrierNV = (PFNGLBLENDBARRIERNVPROC) gl3w__get_proc("glBlendBarrierNV");
	gl3wBlendColor = (PFNGLBLENDCOLORPROC) gl3w__get_proc("glBlendColor");
	gl3wBlendEquation = (PFNGLBLENDEQUATIONPROC) gl3w__get_proc("glBlendEquation");
	gl3wBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) gl3w__get_proc("glBlendEquationSeparate");
	gl3wBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC) gl3w__get_proc("glBlendEquationSeparatei");
	gl3wBlendEquationSeparateiARB = (PFNGLBLENDEQUATIONSEPARATEIARBPROC) gl3w__get_proc("glBlendEquationSeparateiARB");
	gl3wBlendEquationi = (PFNGLBLENDEQUATIONIPROC) gl3w__get_proc("glBlendEquationi");
	gl3wBlendEquationiARB = (PFNGLBLENDEQUATIONIARBPROC) gl3w__get_proc("glBlendEquationiARB");
	gl3wBlendFunc = (PFNGLBLENDFUNCPROC) gl3w__get_proc("glBlendFunc");
	gl3wBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) gl3w__get_proc("glBlendFuncSeparate");
	gl3wBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC) gl3w__get_proc("glBlendFuncSeparatei");
	gl3wBlendFuncSeparateiARB = (PFNGLBLENDFUNCSEPARATEIARBPROC) gl3w__get_proc("glBlendFuncSeparateiARB");
	gl3wBlendFunci = (PFNGLBLENDFUNCIPROC) gl3w__get_proc("glBlendFunci");
	gl3wBlendFunciARB = (PFNGLBLENDFUNCIARBPROC) gl3w__get_proc("glBlendFunciARB");
	gl3wBlendParameteriNV = (PFNGLBLENDPARAMETERINVPROC) gl3w__get_proc("glBlendParameteriNV");
	gl3wBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC) gl3w__get_proc("glBlitFramebuffer");
	gl3wBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC) gl3w__get_proc("glBlitNamedFramebuffer");
	gl3wBufferAddressRangeNV = (PFNGLBUFFERADDRESSRANGENVPROC) gl3w__get_proc("glBufferAddressRangeNV");
	gl3wBufferData = (PFNGLBUFFERDATAPROC) gl3w__get_proc("glBufferData");
	gl3wBufferPageCommitmentARB = (PFNGLBUFFERPAGECOMMITMENTARBPROC) gl3w__get_proc("glBufferPageCommitmentARB");
	gl3wBufferStorage = (PFNGLBUFFERSTORAGEPROC) gl3w__get_proc("glBufferStorage");
	gl3wBufferSubData = (PFNGLBUFFERSUBDATAPROC) gl3w__get_proc("glBufferSubData");
	gl3wCallCommandListNV = (PFNGLCALLCOMMANDLISTNVPROC) gl3w__get_proc("glCallCommandListNV");
	gl3wCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) gl3w__get_proc("glCheckFramebufferStatus");
	gl3wCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) gl3w__get_proc("glCheckNamedFramebufferStatus");
	gl3wCheckNamedFramebufferStatusEXT = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC) gl3w__get_proc("glCheckNamedFramebufferStatusEXT");
	gl3wClampColor = (PFNGLCLAMPCOLORPROC) gl3w__get_proc("glClampColor");
	gl3wClear = (PFNGLCLEARPROC) gl3w__get_proc("glClear");
	gl3wClearBufferData = (PFNGLCLEARBUFFERDATAPROC) gl3w__get_proc("glClearBufferData");
	gl3wClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC) gl3w__get_proc("glClearBufferSubData");
	gl3wClearBufferfi = (PFNGLCLEARBUFFERFIPROC) gl3w__get_proc("glClearBufferfi");
	gl3wClearBufferfv = (PFNGLCLEARBUFFERFVPROC) gl3w__get_proc("glClearBufferfv");
	gl3wClearBufferiv = (PFNGLCLEARBUFFERIVPROC) gl3w__get_proc("glClearBufferiv");
	gl3wClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC) gl3w__get_proc("glClearBufferuiv");
	gl3wClearColor = (PFNGLCLEARCOLORPROC) gl3w__get_proc("glClearColor");
	gl3wClearDepth = (PFNGLCLEARDEPTHPROC) gl3w__get_proc("glClearDepth");
	gl3wClearDepthf = (PFNGLCLEARDEPTHFPROC) gl3w__get_proc("glClearDepthf");
	gl3wClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC) gl3w__get_proc("glClearNamedBufferData");
	gl3wClearNamedBufferDataEXT = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC) gl3w__get_proc("glClearNamedBufferDataEXT");
	gl3wClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC) gl3w__get_proc("glClearNamedBufferSubData");
	gl3wClearNamedBufferSubDataEXT = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC) gl3w__get_proc("glClearNamedBufferSubDataEXT");
	gl3wClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) gl3w__get_proc("glClearNamedFramebufferfi");
	gl3wClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) gl3w__get_proc("glClearNamedFramebufferfv");
	gl3wClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) gl3w__get_proc("glClearNamedFramebufferiv");
	gl3wClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) gl3w__get_proc("glClearNamedFramebufferuiv");
	gl3wClearStencil = (PFNGLCLEARSTENCILPROC) gl3w__get_proc("glClearStencil");
	gl3wClearTexImage = (PFNGLCLEARTEXIMAGEPROC) gl3w__get_proc("glClearTexImage");
	gl3wClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC) gl3w__get_proc("glClearTexSubImage");
	gl3wClientAttribDefaultEXT = (PFNGLCLIENTATTRIBDEFAULTEXTPROC) gl3w__get_proc("glClientAttribDefaultEXT");
	gl3wClientWaitSync = (PFNGLCLIENTWAITSYNCPROC) gl3w__get_proc("glClientWaitSync");
	gl3wClipControl = (PFNGLCLIPCONTROLPROC) gl3w__get_proc("glClipControl");
	gl3wColorFormatNV = (PFNGLCOLORFORMATNVPROC) gl3w__get_proc("glColorFormatNV");
	gl3wColorMask = (PFNGLCOLORMASKPROC) gl3w__get_proc("glColorMask");
	gl3wColorMaski = (PFNGLCOLORMASKIPROC) gl3w__get_proc("glColorMaski");
	gl3wCommandListSegmentsNV = (PFNGLCOMMANDLISTSEGMENTSNVPROC) gl3w__get_proc("glCommandListSegmentsNV");
	gl3wCompileCommandListNV = (PFNGLCOMPILECOMMANDLISTNVPROC) gl3w__get_proc("glCompileCommandListNV");
	gl3wCompileShader = (PFNGLCOMPILESHADERPROC) gl3w__get_proc("glCompileShader");
	gl3wCompileShaderIncludeARB = (PFNGLCOMPILESHADERINCLUDEARBPROC) gl3w__get_proc("glCompileShaderIncludeARB");
	gl3wCompressedMultiTexImage1DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC) gl3w__get_proc("glCompressedMultiTexImage1DEXT");
	gl3wCompressedMultiTexImage2DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC) gl3w__get_proc("glCompressedMultiTexImage2DEXT");
	gl3wCompressedMultiTexImage3DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC) gl3w__get_proc("glCompressedMultiTexImage3DEXT");
	gl3wCompressedMultiTexSubImage1DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC) gl3w__get_proc("glCompressedMultiTexSubImage1DEXT");
	gl3wCompressedMultiTexSubImage2DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC) gl3w__get_proc("glCompressedMultiTexSubImage2DEXT");
	gl3wCompressedMultiTexSubImage3DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC) gl3w__get_proc("glCompressedMultiTexSubImage3DEXT");
	gl3wCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC) gl3w__get_proc("glCompressedTexImage1D");
	gl3wCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) gl3w__get_proc("glCompressedTexImage2D");
	gl3wCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC) gl3w__get_proc("glCompressedTexImage3D");
	gl3wCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) gl3w__get_proc("glCompressedTexSubImage1D");
	gl3wCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) gl3w__get_proc("glCompressedTexSubImage2D");
	gl3wCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) gl3w__get_proc("glCompressedTexSubImage3D");
	gl3wCompressedTextureImage1DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC) gl3w__get_proc("glCompressedTextureImage1DEXT");
	gl3wCompressedTextureImage2DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC) gl3w__get_proc("glCompressedTextureImage2DEXT");
	gl3wCompressedTextureImage3DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC) gl3w__get_proc("glCompressedTextureImage3DEXT");
	gl3wCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) gl3w__get_proc("glCompressedTextureSubImage1D");
	gl3wCompressedTextureSubImage1DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC) gl3w__get_proc("glCompressedTextureSubImage1DEXT");
	gl3wCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) gl3w__get_proc("glCompressedTextureSubImage2D");
	gl3wCompressedTextureSubImage2DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC) gl3w__get_proc("glCompressedTextureSubImage2DEXT");
	gl3wCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) gl3w__get_proc("glCompressedTextureSubImage3D");
	gl3wCompressedTextureSubImage3DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC) gl3w__get_proc("glCompressedTextureSubImage3DEXT");
	gl3wConservativeRasterParameterfNV = (PFNGLCONSERVATIVERASTERPARAMETERFNVPROC) gl3w__get_proc("glConservativeRasterParameterfNV");
	gl3wConservativeRasterParameteriNV = (PFNGLCONSERVATIVERASTERPARAMETERINVPROC) gl3w__get_proc("glConservativeRasterParameteriNV");
	gl3wCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC) gl3w__get_proc("glCopyBufferSubData");
	gl3wCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC) gl3w__get_proc("glCopyImageSubData");
	gl3wCopyMultiTexImage1DEXT = (PFNGLCOPYMULTITEXIMAGE1DEXTPROC) gl3w__get_proc("glCopyMultiTexImage1DEXT");
	gl3wCopyMultiTexImage2DEXT = (PFNGLCOPYMULTITEXIMAGE2DEXTPROC) gl3w__get_proc("glCopyMultiTexImage2DEXT");
	gl3wCopyMultiTexSubImage1DEXT = (PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC) gl3w__get_proc("glCopyMultiTexSubImage1DEXT");
	gl3wCopyMultiTexSubImage2DEXT = (PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC) gl3w__get_proc("glCopyMultiTexSubImage2DEXT");
	gl3wCopyMultiTexSubImage3DEXT = (PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC) gl3w__get_proc("glCopyMultiTexSubImage3DEXT");
	gl3wCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC) gl3w__get_proc("glCopyNamedBufferSubData");
	gl3wCopyPathNV = (PFNGLCOPYPATHNVPROC) gl3w__get_proc("glCopyPathNV");
	gl3wCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC) gl3w__get_proc("glCopyTexImage1D");
	gl3wCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC) gl3w__get_proc("glCopyTexImage2D");
	gl3wCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC) gl3w__get_proc("glCopyTexSubImage1D");
	gl3wCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) gl3w__get_proc("glCopyTexSubImage2D");
	gl3wCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) gl3w__get_proc("glCopyTexSubImage3D");
	gl3wCopyTextureImage1DEXT = (PFNGLCOPYTEXTUREIMAGE1DEXTPROC) gl3w__get_proc("glCopyTextureImage1DEXT");
	gl3wCopyTextureImage2DEXT = (PFNGLCOPYTEXTUREIMAGE2DEXTPROC) gl3w__get_proc("glCopyTextureImage2DEXT");
	gl3wCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC) gl3w__get_proc("glCopyTextureSubImage1D");
	gl3wCopyTextureSubImage1DEXT = (PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC) gl3w__get_proc("glCopyTextureSubImage1DEXT");
	gl3wCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC) gl3w__get_proc("glCopyTextureSubImage2D");
	gl3wCopyTextureSubImage2DEXT = (PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC) gl3w__get_proc("glCopyTextureSubImage2DEXT");
	gl3wCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC) gl3w__get_proc("glCopyTextureSubImage3D");
	gl3wCopyTextureSubImage3DEXT = (PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC) gl3w__get_proc("glCopyTextureSubImage3DEXT");
	gl3wCoverFillPathInstancedNV = (PFNGLCOVERFILLPATHINSTANCEDNVPROC) gl3w__get_proc("glCoverFillPathInstancedNV");
	gl3wCoverFillPathNV = (PFNGLCOVERFILLPATHNVPROC) gl3w__get_proc("glCoverFillPathNV");
	gl3wCoverStrokePathInstancedNV = (PFNGLCOVERSTROKEPATHINSTANCEDNVPROC) gl3w__get_proc("glCoverStrokePathInstancedNV");
	gl3wCoverStrokePathNV = (PFNGLCOVERSTROKEPATHNVPROC) gl3w__get_proc("glCoverStrokePathNV");
	gl3wCoverageModulationNV = (PFNGLCOVERAGEMODULATIONNVPROC) gl3w__get_proc("glCoverageModulationNV");
	gl3wCoverageModulationTableNV = (PFNGLCOVERAGEMODULATIONTABLENVPROC) gl3w__get_proc("glCoverageModulationTableNV");
	gl3wCreateBuffers = (PFNGLCREATEBUFFERSPROC) gl3w__get_proc("glCreateBuffers");
	gl3wCreateCommandListsNV = (PFNGLCREATECOMMANDLISTSNVPROC) gl3w__get_proc("glCreateCommandListsNV");
	gl3wCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC) gl3w__get_proc("glCreateFramebuffers");
	gl3wCreatePerfQueryINTEL = (PFNGLCREATEPERFQUERYINTELPROC) gl3w__get_proc("glCreatePerfQueryINTEL");
	gl3wCreateProgram = (PFNGLCREATEPROGRAMPROC) gl3w__get_proc("glCreateProgram");
	gl3wCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC) gl3w__get_proc("glCreateProgramPipelines");
	gl3wCreateQueries = (PFNGLCREATEQUERIESPROC) gl3w__get_proc("glCreateQueries");
	gl3wCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC) gl3w__get_proc("glCreateRenderbuffers");
	gl3wCreateSamplers = (PFNGLCREATESAMPLERSPROC) gl3w__get_proc("glCreateSamplers");
	gl3wCreateShader = (PFNGLCREATESHADERPROC) gl3w__get_proc("glCreateShader");
	gl3wCreateShaderProgramEXT = (PFNGLCREATESHADERPROGRAMEXTPROC) gl3w__get_proc("glCreateShaderProgramEXT");
	gl3wCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC) gl3w__get_proc("glCreateShaderProgramv");
	gl3wCreateStatesNV = (PFNGLCREATESTATESNVPROC) gl3w__get_proc("glCreateStatesNV");
	gl3wCreateSyncFromCLeventARB = (PFNGLCREATESYNCFROMCLEVENTARBPROC) gl3w__get_proc("glCreateSyncFromCLeventARB");
	gl3wCreateTextures = (PFNGLCREATETEXTURESPROC) gl3w__get_proc("glCreateTextures");
	gl3wCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC) gl3w__get_proc("glCreateTransformFeedbacks");
	gl3wCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC) gl3w__get_proc("glCreateVertexArrays");
	gl3wCullFace = (PFNGLCULLFACEPROC) gl3w__get_proc("glCullFace");
	gl3wDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC) gl3w__get_proc("glDebugMessageCallback");
	gl3wDebugMessageCallbackARB = (PFNGLDEBUGMESSAGECALLBACKARBPROC) gl3w__get_proc("glDebugMessageCallbackARB");
	gl3wDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC) gl3w__get_proc("glDebugMessageControl");
	gl3wDebugMessageControlARB = (PFNGLDEBUGMESSAGECONTROLARBPROC) gl3w__get_proc("glDebugMessageControlARB");
	gl3wDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC) gl3w__get_proc("glDebugMessageInsert");
	gl3wDebugMessageInsertARB = (PFNGLDEBUGMESSAGEINSERTARBPROC) gl3w__get_proc("glDebugMessageInsertARB");
	gl3wDeleteBuffers = (PFNGLDELETEBUFFERSPROC) gl3w__get_proc("glDeleteBuffers");
	gl3wDeleteCommandListsNV = (PFNGLDELETECOMMANDLISTSNVPROC) gl3w__get_proc("glDeleteCommandListsNV");
	gl3wDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC) gl3w__get_proc("glDeleteFramebuffers");
	gl3wDeleteNamedStringARB = (PFNGLDELETENAMEDSTRINGARBPROC) gl3w__get_proc("glDeleteNamedStringARB");
	gl3wDeletePathsNV = (PFNGLDELETEPATHSNVPROC) gl3w__get_proc("glDeletePathsNV");
	gl3wDeletePerfMonitorsAMD = (PFNGLDELETEPERFMONITORSAMDPROC) gl3w__get_proc("glDeletePerfMonitorsAMD");
	gl3wDeletePerfQueryINTEL = (PFNGLDELETEPERFQUERYINTELPROC) gl3w__get_proc("glDeletePerfQueryINTEL");
	gl3wDeleteProgram = (PFNGLDELETEPROGRAMPROC) gl3w__get_proc("glDeleteProgram");
	gl3wDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC) gl3w__get_proc("glDeleteProgramPipelines");
	gl3wDeleteQueries = (PFNGLDELETEQUERIESPROC) gl3w__get_proc("glDeleteQueries");
	gl3wDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC) gl3w__get_proc("glDeleteRenderbuffers");
	gl3wDeleteSamplers = (PFNGLDELETESAMPLERSPROC) gl3w__get_proc("glDeleteSamplers");
	gl3wDeleteShader = (PFNGLDELETESHADERPROC) gl3w__get_proc("glDeleteShader");
	gl3wDeleteStatesNV = (PFNGLDELETESTATESNVPROC) gl3w__get_proc("glDeleteStatesNV");
	gl3wDeleteSync = (PFNGLDELETESYNCPROC) gl3w__get_proc("glDeleteSync");
	gl3wDeleteTextures = (PFNGLDELETETEXTURESPROC) gl3w__get_proc("glDeleteTextures");
	gl3wDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC) gl3w__get_proc("glDeleteTransformFeedbacks");
	gl3wDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC) gl3w__get_proc("glDeleteVertexArrays");
	gl3wDepthFunc = (PFNGLDEPTHFUNCPROC) gl3w__get_proc("glDepthFunc");
	gl3wDepthMask = (PFNGLDEPTHMASKPROC) gl3w__get_proc("glDepthMask");
	gl3wDepthRange = (PFNGLDEPTHRANGEPROC) gl3w__get_proc("glDepthRange");
	gl3wDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC) gl3w__get_proc("glDepthRangeArrayv");
	gl3wDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC) gl3w__get_proc("glDepthRangeIndexed");
	gl3wDepthRangef = (PFNGLDEPTHRANGEFPROC) gl3w__get_proc("glDepthRangef");
	gl3wDetachShader = (PFNGLDETACHSHADERPROC) gl3w__get_proc("glDetachShader");
	gl3wDisable = (PFNGLDISABLEPROC) gl3w__get_proc("glDisable");
	gl3wDisableClientStateIndexedEXT = (PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC) gl3w__get_proc("glDisableClientStateIndexedEXT");
	gl3wDisableClientStateiEXT = (PFNGLDISABLECLIENTSTATEIEXTPROC) gl3w__get_proc("glDisableClientStateiEXT");
	gl3wDisableIndexedEXT = (PFNGLDISABLEINDEXEDEXTPROC) gl3w__get_proc("glDisableIndexedEXT");
	gl3wDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC) gl3w__get_proc("glDisableVertexArrayAttrib");
	gl3wDisableVertexArrayAttribEXT = (PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC) gl3w__get_proc("glDisableVertexArrayAttribEXT");
	gl3wDisableVertexArrayEXT = (PFNGLDISABLEVERTEXARRAYEXTPROC) gl3w__get_proc("glDisableVertexArrayEXT");
	gl3wDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) gl3w__get_proc("glDisableVertexAttribArray");
	gl3wDisablei = (PFNGLDISABLEIPROC) gl3w__get_proc("glDisablei");
	gl3wDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC) gl3w__get_proc("glDispatchCompute");
	gl3wDispatchComputeGroupSizeARB = (PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC) gl3w__get_proc("glDispatchComputeGroupSizeARB");
	gl3wDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC) gl3w__get_proc("glDispatchComputeIndirect");
	gl3wDrawArrays = (PFNGLDRAWARRAYSPROC) gl3w__get_proc("glDrawArrays");
	gl3wDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC) gl3w__get_proc("glDrawArraysIndirect");
	gl3wDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC) gl3w__get_proc("glDrawArraysInstanced");
	gl3wDrawArraysInstancedARB = (PFNGLDRAWARRAYSINSTANCEDARBPROC) gl3w__get_proc("glDrawArraysInstancedARB");
	gl3wDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) gl3w__get_proc("glDrawArraysInstancedBaseInstance");
	gl3wDrawArraysInstancedEXT = (PFNGLDRAWARRAYSINSTANCEDEXTPROC) gl3w__get_proc("glDrawArraysInstancedEXT");
	gl3wDrawBuffer = (PFNGLDRAWBUFFERPROC) gl3w__get_proc("glDrawBuffer");
	gl3wDrawBuffers = (PFNGLDRAWBUFFERSPROC) gl3w__get_proc("glDrawBuffers");
	gl3wDrawCommandsAddressNV = (PFNGLDRAWCOMMANDSADDRESSNVPROC) gl3w__get_proc("glDrawCommandsAddressNV");
	gl3wDrawCommandsNV = (PFNGLDRAWCOMMANDSNVPROC) gl3w__get_proc("glDrawCommandsNV");
	gl3wDrawCommandsStatesAddressNV = (PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC) gl3w__get_proc("glDrawCommandsStatesAddressNV");
	gl3wDrawCommandsStatesNV = (PFNGLDRAWCOMMANDSSTATESNVPROC) gl3w__get_proc("glDrawCommandsStatesNV");
	gl3wDrawElements = (PFNGLDRAWELEMENTSPROC) gl3w__get_proc("glDrawElements");
	gl3wDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC) gl3w__get_proc("glDrawElementsBaseVertex");
	gl3wDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC) gl3w__get_proc("glDrawElementsIndirect");
	gl3wDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC) gl3w__get_proc("glDrawElementsInstanced");
	gl3wDrawElementsInstancedARB = (PFNGLDRAWELEMENTSINSTANCEDARBPROC) gl3w__get_proc("glDrawElementsInstancedARB");
	gl3wDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) gl3w__get_proc("glDrawElementsInstancedBaseInstance");
	gl3wDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) gl3w__get_proc("glDrawElementsInstancedBaseVertex");
	gl3wDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) gl3w__get_proc("glDrawElementsInstancedBaseVertexBaseInstance");
	gl3wDrawElementsInstancedEXT = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC) gl3w__get_proc("glDrawElementsInstancedEXT");
	gl3wDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) gl3w__get_proc("glDrawRangeElements");
	gl3wDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) gl3w__get_proc("glDrawRangeElementsBaseVertex");
	gl3wDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC) gl3w__get_proc("glDrawTransformFeedback");
	gl3wDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) gl3w__get_proc("glDrawTransformFeedbackInstanced");
	gl3wDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) gl3w__get_proc("glDrawTransformFeedbackStream");
	gl3wDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) gl3w__get_proc("glDrawTransformFeedbackStreamInstanced");
	gl3wDrawVkImageNV = (PFNGLDRAWVKIMAGENVPROC) gl3w__get_proc("glDrawVkImageNV");
	gl3wEdgeFlagFormatNV = (PFNGLEDGEFLAGFORMATNVPROC) gl3w__get_proc("glEdgeFlagFormatNV");
	gl3wEnable = (PFNGLENABLEPROC) gl3w__get_proc("glEnable");
	gl3wEnableClientStateIndexedEXT = (PFNGLENABLECLIENTSTATEINDEXEDEXTPROC) gl3w__get_proc("glEnableClientStateIndexedEXT");
	gl3wEnableClientStateiEXT = (PFNGLENABLECLIENTSTATEIEXTPROC) gl3w__get_proc("glEnableClientStateiEXT");
	gl3wEnableIndexedEXT = (PFNGLENABLEINDEXEDEXTPROC) gl3w__get_proc("glEnableIndexedEXT");
	gl3wEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC) gl3w__get_proc("glEnableVertexArrayAttrib");
	gl3wEnableVertexArrayAttribEXT = (PFNGLENABLEVERTEXARRAYATTRIBEXTPROC) gl3w__get_proc("glEnableVertexArrayAttribEXT");
	gl3wEnableVertexArrayEXT = (PFNGLENABLEVERTEXARRAYEXTPROC) gl3w__get_proc("glEnableVertexArrayEXT");
	gl3wEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) gl3w__get_proc("glEnableVertexAttribArray");
	gl3wEnablei = (PFNGLENABLEIPROC) gl3w__get_proc("glEnablei");
	gl3wEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC) gl3w__get_proc("glEndConditionalRender");
	gl3wEndConditionalRenderNV = (PFNGLENDCONDITIONALRENDERNVPROC) gl3w__get_proc("glEndConditionalRenderNV");
	gl3wEndPerfMonitorAMD = (PFNGLENDPERFMONITORAMDPROC) gl3w__get_proc("glEndPerfMonitorAMD");
	gl3wEndPerfQueryINTEL = (PFNGLENDPERFQUERYINTELPROC) gl3w__get_proc("glEndPerfQueryINTEL");
	gl3wEndQuery = (PFNGLENDQUERYPROC) gl3w__get_proc("glEndQuery");
	gl3wEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC) gl3w__get_proc("glEndQueryIndexed");
	gl3wEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC) gl3w__get_proc("glEndTransformFeedback");
	gl3wEvaluateDepthValuesARB = (PFNGLEVALUATEDEPTHVALUESARBPROC) gl3w__get_proc("glEvaluateDepthValuesARB");
	gl3wFenceSync = (PFNGLFENCESYNCPROC) gl3w__get_proc("glFenceSync");
	gl3wFinish = (PFNGLFINISHPROC) gl3w__get_proc("glFinish");
	gl3wFlush = (PFNGLFLUSHPROC) gl3w__get_proc("glFlush");
	gl3wFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC) gl3w__get_proc("glFlushMappedBufferRange");
	gl3wFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) gl3w__get_proc("glFlushMappedNamedBufferRange");
	gl3wFlushMappedNamedBufferRangeEXT = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC) gl3w__get_proc("glFlushMappedNamedBufferRangeEXT");
	gl3wFogCoordFormatNV = (PFNGLFOGCOORDFORMATNVPROC) gl3w__get_proc("glFogCoordFormatNV");
	gl3wFragmentCoverageColorNV = (PFNGLFRAGMENTCOVERAGECOLORNVPROC) gl3w__get_proc("glFragmentCoverageColorNV");
	gl3wFramebufferDrawBufferEXT = (PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC) gl3w__get_proc("glFramebufferDrawBufferEXT");
	gl3wFramebufferDrawBuffersEXT = (PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC) gl3w__get_proc("glFramebufferDrawBuffersEXT");
	gl3wFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC) gl3w__get_proc("glFramebufferParameteri");
	gl3wFramebufferReadBufferEXT = (PFNGLFRAMEBUFFERREADBUFFEREXTPROC) gl3w__get_proc("glFramebufferReadBufferEXT");
	gl3wFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC) gl3w__get_proc("glFramebufferRenderbuffer");
	gl3wFramebufferSampleLocationsfvARB = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC) gl3w__get_proc("glFramebufferSampleLocationsfvARB");
	gl3wFramebufferSampleLocationsfvNV = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC) gl3w__get_proc("glFramebufferSampleLocationsfvNV");
	gl3wFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC) gl3w__get_proc("glFramebufferTexture");
	gl3wFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC) gl3w__get_proc("glFramebufferTexture1D");
	gl3wFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC) gl3w__get_proc("glFramebufferTexture2D");
	gl3wFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC) gl3w__get_proc("glFramebufferTexture3D");
	gl3wFramebufferTextureARB = (PFNGLFRAMEBUFFERTEXTUREARBPROC) gl3w__get_proc("glFramebufferTextureARB");
	gl3wFramebufferTextureFaceARB = (PFNGLFRAMEBUFFERTEXTUREFACEARBPROC) gl3w__get_proc("glFramebufferTextureFaceARB");
	gl3wFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC) gl3w__get_proc("glFramebufferTextureLayer");
	gl3wFramebufferTextureLayerARB = (PFNGLFRAMEBUFFERTEXTURELAYERARBPROC) gl3w__get_proc("glFramebufferTextureLayerARB");
	gl3wFramebufferTextureMultiviewOVR = (PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC) gl3w__get_proc("glFramebufferTextureMultiviewOVR");
	gl3wFrontFace = (PFNGLFRONTFACEPROC) gl3w__get_proc("glFrontFace");
	gl3wGenBuffers = (PFNGLGENBUFFERSPROC) gl3w__get_proc("glGenBuffers");
	gl3wGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) gl3w__get_proc("glGenFramebuffers");
	gl3wGenPathsNV = (PFNGLGENPATHSNVPROC) gl3w__get_proc("glGenPathsNV");
	gl3wGenPerfMonitorsAMD = (PFNGLGENPERFMONITORSAMDPROC) gl3w__get_proc("glGenPerfMonitorsAMD");
	gl3wGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC) gl3w__get_proc("glGenProgramPipelines");
	gl3wGenQueries = (PFNGLGENQUERIESPROC) gl3w__get_proc("glGenQueries");
	gl3wGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC) gl3w__get_proc("glGenRenderbuffers");
	gl3wGenSamplers = (PFNGLGENSAMPLERSPROC) gl3w__get_proc("glGenSamplers");
	gl3wGenTextures = (PFNGLGENTEXTURESPROC) gl3w__get_proc("glGenTextures");
	gl3wGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC) gl3w__get_proc("glGenTransformFeedbacks");
	gl3wGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC) gl3w__get_proc("glGenVertexArrays");
	gl3wGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) gl3w__get_proc("glGenerateMipmap");
	gl3wGenerateMultiTexMipmapEXT = (PFNGLGENERATEMULTITEXMIPMAPEXTPROC) gl3w__get_proc("glGenerateMultiTexMipmapEXT");
	gl3wGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC) gl3w__get_proc("glGenerateTextureMipmap");
	gl3wGenerateTextureMipmapEXT = (PFNGLGENERATETEXTUREMIPMAPEXTPROC) gl3w__get_proc("glGenerateTextureMipmapEXT");
	gl3wGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) gl3w__get_proc("glGetActiveAtomicCounterBufferiv");
	gl3wGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC) gl3w__get_proc("glGetActiveAttrib");
	gl3wGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC) gl3w__get_proc("glGetActiveSubroutineName");
	gl3wGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) gl3w__get_proc("glGetActiveSubroutineUniformName");
	gl3wGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) gl3w__get_proc("glGetActiveSubroutineUniformiv");
	gl3wGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) gl3w__get_proc("glGetActiveUniform");
	gl3wGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) gl3w__get_proc("glGetActiveUniformBlockName");
	gl3wGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC) gl3w__get_proc("glGetActiveUniformBlockiv");
	gl3wGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC) gl3w__get_proc("glGetActiveUniformName");
	gl3wGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC) gl3w__get_proc("glGetActiveUniformsiv");
	gl3wGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) gl3w__get_proc("glGetAttachedShaders");
	gl3wGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) gl3w__get_proc("glGetAttribLocation");
	gl3wGetBooleanIndexedvEXT = (PFNGLGETBOOLEANINDEXEDVEXTPROC) gl3w__get_proc("glGetBooleanIndexedvEXT");
	gl3wGetBooleani_v = (PFNGLGETBOOLEANI_VPROC) gl3w__get_proc("glGetBooleani_v");
	gl3wGetBooleanv = (PFNGLGETBOOLEANVPROC) gl3w__get_proc("glGetBooleanv");
	gl3wGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC) gl3w__get_proc("glGetBufferParameteri64v");
	gl3wGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) gl3w__get_proc("glGetBufferParameteriv");
	gl3wGetBufferParameterui64vNV = (PFNGLGETBUFFERPARAMETERUI64VNVPROC) gl3w__get_proc("glGetBufferParameterui64vNV");
	gl3wGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC) gl3w__get_proc("glGetBufferPointerv");
	gl3wGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC) gl3w__get_proc("glGetBufferSubData");
	gl3wGetCommandHeaderNV = (PFNGLGETCOMMANDHEADERNVPROC) gl3w__get_proc("glGetCommandHeaderNV");
	gl3wGetCompressedMultiTexImageEXT = (PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC) gl3w__get_proc("glGetCompressedMultiTexImageEXT");
	gl3wGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC) gl3w__get_proc("glGetCompressedTexImage");
	gl3wGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) gl3w__get_proc("glGetCompressedTextureImage");
	gl3wGetCompressedTextureImageEXT = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC) gl3w__get_proc("glGetCompressedTextureImageEXT");
	gl3wGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) gl3w__get_proc("glGetCompressedTextureSubImage");
	gl3wGetCoverageModulationTableNV = (PFNGLGETCOVERAGEMODULATIONTABLENVPROC) gl3w__get_proc("glGetCoverageModulationTableNV");
	gl3wGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC) gl3w__get_proc("glGetDebugMessageLog");
	gl3wGetDebugMessageLogARB = (PFNGLGETDEBUGMESSAGELOGARBPROC) gl3w__get_proc("glGetDebugMessageLogARB");
	gl3wGetDoubleIndexedvEXT = (PFNGLGETDOUBLEINDEXEDVEXTPROC) gl3w__get_proc("glGetDoubleIndexedvEXT");
	gl3wGetDoublei_v = (PFNGLGETDOUBLEI_VPROC) gl3w__get_proc("glGetDoublei_v");
	gl3wGetDoublei_vEXT = (PFNGLGETDOUBLEI_VEXTPROC) gl3w__get_proc("glGetDoublei_vEXT");
	gl3wGetDoublev = (PFNGLGETDOUBLEVPROC) gl3w__get_proc("glGetDoublev");
	gl3wGetError = (PFNGLGETERRORPROC) gl3w__get_proc("glGetError");
	gl3wGetFirstPerfQueryIdINTEL = (PFNGLGETFIRSTPERFQUERYIDINTELPROC) gl3w__get_proc("glGetFirstPerfQueryIdINTEL");
	gl3wGetFloatIndexedvEXT = (PFNGLGETFLOATINDEXEDVEXTPROC) gl3w__get_proc("glGetFloatIndexedvEXT");
	gl3wGetFloati_v = (PFNGLGETFLOATI_VPROC) gl3w__get_proc("glGetFloati_v");
	gl3wGetFloati_vEXT = (PFNGLGETFLOATI_VEXTPROC) gl3w__get_proc("glGetFloati_vEXT");
	gl3wGetFloatv = (PFNGLGETFLOATVPROC) gl3w__get_proc("glGetFloatv");
	gl3wGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC) gl3w__get_proc("glGetFragDataIndex");
	gl3wGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC) gl3w__get_proc("glGetFragDataLocation");
	gl3wGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) gl3w__get_proc("glGetFramebufferAttachmentParameteriv");
	gl3wGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC) gl3w__get_proc("glGetFramebufferParameteriv");
	gl3wGetFramebufferParameterivEXT = (PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC) gl3w__get_proc("glGetFramebufferParameterivEXT");
	gl3wGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC) gl3w__get_proc("glGetGraphicsResetStatus");
	gl3wGetGraphicsResetStatusARB = (PFNGLGETGRAPHICSRESETSTATUSARBPROC) gl3w__get_proc("glGetGraphicsResetStatusARB");
	gl3wGetImageHandleARB = (PFNGLGETIMAGEHANDLEARBPROC) gl3w__get_proc("glGetImageHandleARB");
	gl3wGetImageHandleNV = (PFNGLGETIMAGEHANDLENVPROC) gl3w__get_proc("glGetImageHandleNV");
	gl3wGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC) gl3w__get_proc("glGetInteger64i_v");
	gl3wGetInteger64v = (PFNGLGETINTEGER64VPROC) gl3w__get_proc("glGetInteger64v");
	gl3wGetIntegerIndexedvEXT = (PFNGLGETINTEGERINDEXEDVEXTPROC) gl3w__get_proc("glGetIntegerIndexedvEXT");
	gl3wGetIntegeri_v = (PFNGLGETINTEGERI_VPROC) gl3w__get_proc("glGetIntegeri_v");
	gl3wGetIntegerui64i_vNV = (PFNGLGETINTEGERUI64I_VNVPROC) gl3w__get_proc("glGetIntegerui64i_vNV");
	gl3wGetIntegerui64vNV = (PFNGLGETINTEGERUI64VNVPROC) gl3w__get_proc("glGetIntegerui64vNV");
	gl3wGetIntegerv = (PFNGLGETINTEGERVPROC) gl3w__get_proc("glGetIntegerv");
	gl3wGetInternalformatSampleivNV = (PFNGLGETINTERNALFORMATSAMPLEIVNVPROC) gl3w__get_proc("glGetInternalformatSampleivNV");
	gl3wGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC) gl3w__get_proc("glGetInternalformati64v");
	gl3wGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC) gl3w__get_proc("glGetInternalformativ");
	gl3wGetMultiTexEnvfvEXT = (PFNGLGETMULTITEXENVFVEXTPROC) gl3w__get_proc("glGetMultiTexEnvfvEXT");
	gl3wGetMultiTexEnvivEXT = (PFNGLGETMULTITEXENVIVEXTPROC) gl3w__get_proc("glGetMultiTexEnvivEXT");
	gl3wGetMultiTexGendvEXT = (PFNGLGETMULTITEXGENDVEXTPROC) gl3w__get_proc("glGetMultiTexGendvEXT");
	gl3wGetMultiTexGenfvEXT = (PFNGLGETMULTITEXGENFVEXTPROC) gl3w__get_proc("glGetMultiTexGenfvEXT");
	gl3wGetMultiTexGenivEXT = (PFNGLGETMULTITEXGENIVEXTPROC) gl3w__get_proc("glGetMultiTexGenivEXT");
	gl3wGetMultiTexImageEXT = (PFNGLGETMULTITEXIMAGEEXTPROC) gl3w__get_proc("glGetMultiTexImageEXT");
	gl3wGetMultiTexLevelParameterfvEXT = (PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC) gl3w__get_proc("glGetMultiTexLevelParameterfvEXT");
	gl3wGetMultiTexLevelParameterivEXT = (PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC) gl3w__get_proc("glGetMultiTexLevelParameterivEXT");
	gl3wGetMultiTexParameterIivEXT = (PFNGLGETMULTITEXPARAMETERIIVEXTPROC) gl3w__get_proc("glGetMultiTexParameterIivEXT");
	gl3wGetMultiTexParameterIuivEXT = (PFNGLGETMULTITEXPARAMETERIUIVEXTPROC) gl3w__get_proc("glGetMultiTexParameterIuivEXT");
	gl3wGetMultiTexParameterfvEXT = (PFNGLGETMULTITEXPARAMETERFVEXTPROC) gl3w__get_proc("glGetMultiTexParameterfvEXT");
	gl3wGetMultiTexParameterivEXT = (PFNGLGETMULTITEXPARAMETERIVEXTPROC) gl3w__get_proc("glGetMultiTexParameterivEXT");
	gl3wGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC) gl3w__get_proc("glGetMultisamplefv");
	gl3wGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) gl3w__get_proc("glGetNamedBufferParameteri64v");
	gl3wGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC) gl3w__get_proc("glGetNamedBufferParameteriv");
	gl3wGetNamedBufferParameterivEXT = (PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC) gl3w__get_proc("glGetNamedBufferParameterivEXT");
	gl3wGetNamedBufferParameterui64vNV = (PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC) gl3w__get_proc("glGetNamedBufferParameterui64vNV");
	gl3wGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC) gl3w__get_proc("glGetNamedBufferPointerv");
	gl3wGetNamedBufferPointervEXT = (PFNGLGETNAMEDBUFFERPOINTERVEXTPROC) gl3w__get_proc("glGetNamedBufferPointervEXT");
	gl3wGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC) gl3w__get_proc("glGetNamedBufferSubData");
	gl3wGetNamedBufferSubDataEXT = (PFNGLGETNAMEDBUFFERSUBDATAEXTPROC) gl3w__get_proc("glGetNamedBufferSubDataEXT");
	gl3wGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) gl3w__get_proc("glGetNamedFramebufferAttachmentParameteriv");
	gl3wGetNamedFramebufferAttachmentParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) gl3w__get_proc("glGetNamedFramebufferAttachmentParameterivEXT");
	gl3wGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) gl3w__get_proc("glGetNamedFramebufferParameteriv");
	gl3wGetNamedFramebufferParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC) gl3w__get_proc("glGetNamedFramebufferParameterivEXT");
	gl3wGetNamedProgramLocalParameterIivEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC) gl3w__get_proc("glGetNamedProgramLocalParameterIivEXT");
	gl3wGetNamedProgramLocalParameterIuivEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC) gl3w__get_proc("glGetNamedProgramLocalParameterIuivEXT");
	gl3wGetNamedProgramLocalParameterdvEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC) gl3w__get_proc("glGetNamedProgramLocalParameterdvEXT");
	gl3wGetNamedProgramLocalParameterfvEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC) gl3w__get_proc("glGetNamedProgramLocalParameterfvEXT");
	gl3wGetNamedProgramStringEXT = (PFNGLGETNAMEDPROGRAMSTRINGEXTPROC) gl3w__get_proc("glGetNamedProgramStringEXT");
	gl3wGetNamedProgramivEXT = (PFNGLGETNAMEDPROGRAMIVEXTPROC) gl3w__get_proc("glGetNamedProgramivEXT");
	gl3wGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) gl3w__get_proc("glGetNamedRenderbufferParameteriv");
	gl3wGetNamedRenderbufferParameterivEXT = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC) gl3w__get_proc("glGetNamedRenderbufferParameterivEXT");
	gl3wGetNamedStringARB = (PFNGLGETNAMEDSTRINGARBPROC) gl3w__get_proc("glGetNamedStringARB");
	gl3wGetNamedStringivARB = (PFNGLGETNAMEDSTRINGIVARBPROC) gl3w__get_proc("glGetNamedStringivARB");
	gl3wGetNextPerfQueryIdINTEL = (PFNGLGETNEXTPERFQUERYIDINTELPROC) gl3w__get_proc("glGetNextPerfQueryIdINTEL");
	gl3wGetObjectLabel = (PFNGLGETOBJECTLABELPROC) gl3w__get_proc("glGetObjectLabel");
	gl3wGetObjectLabelEXT = (PFNGLGETOBJECTLABELEXTPROC) gl3w__get_proc("glGetObjectLabelEXT");
	gl3wGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC) gl3w__get_proc("glGetObjectPtrLabel");
	gl3wGetPathCommandsNV = (PFNGLGETPATHCOMMANDSNVPROC) gl3w__get_proc("glGetPathCommandsNV");
	gl3wGetPathCoordsNV = (PFNGLGETPATHCOORDSNVPROC) gl3w__get_proc("glGetPathCoordsNV");
	gl3wGetPathDashArrayNV = (PFNGLGETPATHDASHARRAYNVPROC) gl3w__get_proc("glGetPathDashArrayNV");
	gl3wGetPathLengthNV = (PFNGLGETPATHLENGTHNVPROC) gl3w__get_proc("glGetPathLengthNV");
	gl3wGetPathMetricRangeNV = (PFNGLGETPATHMETRICRANGENVPROC) gl3w__get_proc("glGetPathMetricRangeNV");
	gl3wGetPathMetricsNV = (PFNGLGETPATHMETRICSNVPROC) gl3w__get_proc("glGetPathMetricsNV");
	gl3wGetPathParameterfvNV = (PFNGLGETPATHPARAMETERFVNVPROC) gl3w__get_proc("glGetPathParameterfvNV");
	gl3wGetPathParameterivNV = (PFNGLGETPATHPARAMETERIVNVPROC) gl3w__get_proc("glGetPathParameterivNV");
	gl3wGetPathSpacingNV = (PFNGLGETPATHSPACINGNVPROC) gl3w__get_proc("glGetPathSpacingNV");
	gl3wGetPerfCounterInfoINTEL = (PFNGLGETPERFCOUNTERINFOINTELPROC) gl3w__get_proc("glGetPerfCounterInfoINTEL");
	gl3wGetPerfMonitorCounterDataAMD = (PFNGLGETPERFMONITORCOUNTERDATAAMDPROC) gl3w__get_proc("glGetPerfMonitorCounterDataAMD");
	gl3wGetPerfMonitorCounterInfoAMD = (PFNGLGETPERFMONITORCOUNTERINFOAMDPROC) gl3w__get_proc("glGetPerfMonitorCounterInfoAMD");
	gl3wGetPerfMonitorCounterStringAMD = (PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC) gl3w__get_proc("glGetPerfMonitorCounterStringAMD");
	gl3wGetPerfMonitorCountersAMD = (PFNGLGETPERFMONITORCOUNTERSAMDPROC) gl3w__get_proc("glGetPerfMonitorCountersAMD");
	gl3wGetPerfMonitorGroupStringAMD = (PFNGLGETPERFMONITORGROUPSTRINGAMDPROC) gl3w__get_proc("glGetPerfMonitorGroupStringAMD");
	gl3wGetPerfMonitorGroupsAMD = (PFNGLGETPERFMONITORGROUPSAMDPROC) gl3w__get_proc("glGetPerfMonitorGroupsAMD");
	gl3wGetPerfQueryDataINTEL = (PFNGLGETPERFQUERYDATAINTELPROC) gl3w__get_proc("glGetPerfQueryDataINTEL");
	gl3wGetPerfQueryIdByNameINTEL = (PFNGLGETPERFQUERYIDBYNAMEINTELPROC) gl3w__get_proc("glGetPerfQueryIdByNameINTEL");
	gl3wGetPerfQueryInfoINTEL = (PFNGLGETPERFQUERYINFOINTELPROC) gl3w__get_proc("glGetPerfQueryInfoINTEL");
	gl3wGetPointerIndexedvEXT = (PFNGLGETPOINTERINDEXEDVEXTPROC) gl3w__get_proc("glGetPointerIndexedvEXT");
	gl3wGetPointeri_vEXT = (PFNGLGETPOINTERI_VEXTPROC) gl3w__get_proc("glGetPointeri_vEXT");
	gl3wGetPointerv = (PFNGLGETPOINTERVPROC) gl3w__get_proc("glGetPointerv");
	gl3wGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC) gl3w__get_proc("glGetProgramBinary");
	gl3wGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) gl3w__get_proc("glGetProgramInfoLog");
	gl3wGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC) gl3w__get_proc("glGetProgramInterfaceiv");
	gl3wGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC) gl3w__get_proc("glGetProgramPipelineInfoLog");
	gl3wGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC) gl3w__get_proc("glGetProgramPipelineiv");
	gl3wGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC) gl3w__get_proc("glGetProgramResourceIndex");
	gl3wGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC) gl3w__get_proc("glGetProgramResourceLocation");
	gl3wGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) gl3w__get_proc("glGetProgramResourceLocationIndex");
	gl3wGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC) gl3w__get_proc("glGetProgramResourceName");
	gl3wGetProgramResourcefvNV = (PFNGLGETPROGRAMRESOURCEFVNVPROC) gl3w__get_proc("glGetProgramResourcefvNV");
	gl3wGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC) gl3w__get_proc("glGetProgramResourceiv");
	gl3wGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC) gl3w__get_proc("glGetProgramStageiv");
	gl3wGetProgramiv = (PFNGLGETPROGRAMIVPROC) gl3w__get_proc("glGetProgramiv");
	gl3wGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC) gl3w__get_proc("glGetQueryBufferObjecti64v");
	gl3wGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC) gl3w__get_proc("glGetQueryBufferObjectiv");
	gl3wGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC) gl3w__get_proc("glGetQueryBufferObjectui64v");
	gl3wGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC) gl3w__get_proc("glGetQueryBufferObjectuiv");
	gl3wGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC) gl3w__get_proc("glGetQueryIndexediv");
	gl3wGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC) gl3w__get_proc("glGetQueryObjecti64v");
	gl3wGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC) gl3w__get_proc("glGetQueryObjectiv");
	gl3wGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC) gl3w__get_proc("glGetQueryObjectui64v");
	gl3wGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC) gl3w__get_proc("glGetQueryObjectuiv");
	gl3wGetQueryiv = (PFNGLGETQUERYIVPROC) gl3w__get_proc("glGetQueryiv");
	gl3wGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC) gl3w__get_proc("glGetRenderbufferParameteriv");
	gl3wGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC) gl3w__get_proc("glGetSamplerParameterIiv");
	gl3wGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC) gl3w__get_proc("glGetSamplerParameterIuiv");
	gl3wGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC) gl3w__get_proc("glGetSamplerParameterfv");
	gl3wGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC) gl3w__get_proc("glGetSamplerParameteriv");
	gl3wGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) gl3w__get_proc("glGetShaderInfoLog");
	gl3wGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC) gl3w__get_proc("glGetShaderPrecisionFormat");
	gl3wGetShaderSource = (PFNGLGETSHADERSOURCEPROC) gl3w__get_proc("glGetShaderSource");
	gl3wGetShaderiv = (PFNGLGETSHADERIVPROC) gl3w__get_proc("glGetShaderiv");
	gl3wGetStageIndexNV = (PFNGLGETSTAGEINDEXNVPROC) gl3w__get_proc("glGetStageIndexNV");
	gl3wGetString = (PFNGLGETSTRINGPROC) gl3w__get_proc("glGetString");
	gl3wGetStringi = (PFNGLGETSTRINGIPROC) gl3w__get_proc("glGetStringi");
	gl3wGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC) gl3w__get_proc("glGetSubroutineIndex");
	gl3wGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) gl3w__get_proc("glGetSubroutineUniformLocation");
	gl3wGetSynciv = (PFNGLGETSYNCIVPROC) gl3w__get_proc("glGetSynciv");
	gl3wGetTexImage = (PFNGLGETTEXIMAGEPROC) gl3w__get_proc("glGetTexImage");
	gl3wGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC) gl3w__get_proc("glGetTexLevelParameterfv");
	gl3wGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC) gl3w__get_proc("glGetTexLevelParameteriv");
	gl3wGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC) gl3w__get_proc("glGetTexParameterIiv");
	gl3wGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC) gl3w__get_proc("glGetTexParameterIuiv");
	gl3wGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC) gl3w__get_proc("glGetTexParameterfv");
	gl3wGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC) gl3w__get_proc("glGetTexParameteriv");
	gl3wGetTextureHandleARB = (PFNGLGETTEXTUREHANDLEARBPROC) gl3w__get_proc("glGetTextureHandleARB");
	gl3wGetTextureHandleNV = (PFNGLGETTEXTUREHANDLENVPROC) gl3w__get_proc("glGetTextureHandleNV");
	gl3wGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC) gl3w__get_proc("glGetTextureImage");
	gl3wGetTextureImageEXT = (PFNGLGETTEXTUREIMAGEEXTPROC) gl3w__get_proc("glGetTextureImageEXT");
	gl3wGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC) gl3w__get_proc("glGetTextureLevelParameterfv");
	gl3wGetTextureLevelParameterfvEXT = (PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC) gl3w__get_proc("glGetTextureLevelParameterfvEXT");
	gl3wGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC) gl3w__get_proc("glGetTextureLevelParameteriv");
	gl3wGetTextureLevelParameterivEXT = (PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC) gl3w__get_proc("glGetTextureLevelParameterivEXT");
	gl3wGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC) gl3w__get_proc("glGetTextureParameterIiv");
	gl3wGetTextureParameterIivEXT = (PFNGLGETTEXTUREPARAMETERIIVEXTPROC) gl3w__get_proc("glGetTextureParameterIivEXT");
	gl3wGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC) gl3w__get_proc("glGetTextureParameterIuiv");
	gl3wGetTextureParameterIuivEXT = (PFNGLGETTEXTUREPARAMETERIUIVEXTPROC) gl3w__get_proc("glGetTextureParameterIuivEXT");
	gl3wGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC) gl3w__get_proc("glGetTextureParameterfv");
	gl3wGetTextureParameterfvEXT = (PFNGLGETTEXTUREPARAMETERFVEXTPROC) gl3w__get_proc("glGetTextureParameterfvEXT");
	gl3wGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC) gl3w__get_proc("glGetTextureParameteriv");
	gl3wGetTextureParameterivEXT = (PFNGLGETTEXTUREPARAMETERIVEXTPROC) gl3w__get_proc("glGetTextureParameterivEXT");
	gl3wGetTextureSamplerHandleARB = (PFNGLGETTEXTURESAMPLERHANDLEARBPROC) gl3w__get_proc("glGetTextureSamplerHandleARB");
	gl3wGetTextureSamplerHandleNV = (PFNGLGETTEXTURESAMPLERHANDLENVPROC) gl3w__get_proc("glGetTextureSamplerHandleNV");
	gl3wGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC) gl3w__get_proc("glGetTextureSubImage");
	gl3wGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) gl3w__get_proc("glGetTransformFeedbackVarying");
	gl3wGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC) gl3w__get_proc("glGetTransformFeedbacki64_v");
	gl3wGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC) gl3w__get_proc("glGetTransformFeedbacki_v");
	gl3wGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC) gl3w__get_proc("glGetTransformFeedbackiv");
	gl3wGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC) gl3w__get_proc("glGetUniformBlockIndex");
	gl3wGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC) gl3w__get_proc("glGetUniformIndices");
	gl3wGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) gl3w__get_proc("glGetUniformLocation");
	gl3wGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC) gl3w__get_proc("glGetUniformSubroutineuiv");
	gl3wGetUniformdv = (PFNGLGETUNIFORMDVPROC) gl3w__get_proc("glGetUniformdv");
	gl3wGetUniformfv = (PFNGLGETUNIFORMFVPROC) gl3w__get_proc("glGetUniformfv");
	gl3wGetUniformi64vARB = (PFNGLGETUNIFORMI64VARBPROC) gl3w__get_proc("glGetUniformi64vARB");
	gl3wGetUniformi64vNV = (PFNGLGETUNIFORMI64VNVPROC) gl3w__get_proc("glGetUniformi64vNV");
	gl3wGetUniformiv = (PFNGLGETUNIFORMIVPROC) gl3w__get_proc("glGetUniformiv");
	gl3wGetUniformui64vARB = (PFNGLGETUNIFORMUI64VARBPROC) gl3w__get_proc("glGetUniformui64vARB");
	gl3wGetUniformui64vNV = (PFNGLGETUNIFORMUI64VNVPROC) gl3w__get_proc("glGetUniformui64vNV");
	gl3wGetUniformuiv = (PFNGLGETUNIFORMUIVPROC) gl3w__get_proc("glGetUniformuiv");
	gl3wGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC) gl3w__get_proc("glGetVertexArrayIndexed64iv");
	gl3wGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC) gl3w__get_proc("glGetVertexArrayIndexediv");
	gl3wGetVertexArrayIntegeri_vEXT = (PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC) gl3w__get_proc("glGetVertexArrayIntegeri_vEXT");
	gl3wGetVertexArrayIntegervEXT = (PFNGLGETVERTEXARRAYINTEGERVEXTPROC) gl3w__get_proc("glGetVertexArrayIntegervEXT");
	gl3wGetVertexArrayPointeri_vEXT = (PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC) gl3w__get_proc("glGetVertexArrayPointeri_vEXT");
	gl3wGetVertexArrayPointervEXT = (PFNGLGETVERTEXARRAYPOINTERVEXTPROC) gl3w__get_proc("glGetVertexArrayPointervEXT");
	gl3wGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC) gl3w__get_proc("glGetVertexArrayiv");
	gl3wGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC) gl3w__get_proc("glGetVertexAttribIiv");
	gl3wGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC) gl3w__get_proc("glGetVertexAttribIuiv");
	gl3wGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC) gl3w__get_proc("glGetVertexAttribLdv");
	gl3wGetVertexAttribLi64vNV = (PFNGLGETVERTEXATTRIBLI64VNVPROC) gl3w__get_proc("glGetVertexAttribLi64vNV");
	gl3wGetVertexAttribLui64vARB = (PFNGLGETVERTEXATTRIBLUI64VARBPROC) gl3w__get_proc("glGetVertexAttribLui64vARB");
	gl3wGetVertexAttribLui64vNV = (PFNGLGETVERTEXATTRIBLUI64VNVPROC) gl3w__get_proc("glGetVertexAttribLui64vNV");
	gl3wGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC) gl3w__get_proc("glGetVertexAttribPointerv");
	gl3wGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC) gl3w__get_proc("glGetVertexAttribdv");
	gl3wGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC) gl3w__get_proc("glGetVertexAttribfv");
	gl3wGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC) gl3w__get_proc("glGetVertexAttribiv");
	gl3wGetVkProcAddrNV = (PFNGLGETVKPROCADDRNVPROC) gl3w__get_proc("glGetVkProcAddrNV");
	gl3wGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC) gl3w__get_proc("glGetnCompressedTexImage");
	gl3wGetnCompressedTexImageARB = (PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC) gl3w__get_proc("glGetnCompressedTexImageARB");
	gl3wGetnTexImage = (PFNGLGETNTEXIMAGEPROC) gl3w__get_proc("glGetnTexImage");
	gl3wGetnTexImageARB = (PFNGLGETNTEXIMAGEARBPROC) gl3w__get_proc("glGetnTexImageARB");
	gl3wGetnUniformdv = (PFNGLGETNUNIFORMDVPROC) gl3w__get_proc("glGetnUniformdv");
	gl3wGetnUniformdvARB = (PFNGLGETNUNIFORMDVARBPROC) gl3w__get_proc("glGetnUniformdvARB");
	gl3wGetnUniformfv = (PFNGLGETNUNIFORMFVPROC) gl3w__get_proc("glGetnUniformfv");
	gl3wGetnUniformfvARB = (PFNGLGETNUNIFORMFVARBPROC) gl3w__get_proc("glGetnUniformfvARB");
	gl3wGetnUniformi64vARB = (PFNGLGETNUNIFORMI64VARBPROC) gl3w__get_proc("glGetnUniformi64vARB");
	gl3wGetnUniformiv = (PFNGLGETNUNIFORMIVPROC) gl3w__get_proc("glGetnUniformiv");
	gl3wGetnUniformivARB = (PFNGLGETNUNIFORMIVARBPROC) gl3w__get_proc("glGetnUniformivARB");
	gl3wGetnUniformui64vARB = (PFNGLGETNUNIFORMUI64VARBPROC) gl3w__get_proc("glGetnUniformui64vARB");
	gl3wGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC) gl3w__get_proc("glGetnUniformuiv");
	gl3wGetnUniformuivARB = (PFNGLGETNUNIFORMUIVARBPROC) gl3w__get_proc("glGetnUniformuivARB");
	gl3wHint = (PFNGLHINTPROC) gl3w__get_proc("glHint");
	gl3wIndexFormatNV = (PFNGLINDEXFORMATNVPROC) gl3w__get_proc("glIndexFormatNV");
	gl3wInsertEventMarkerEXT = (PFNGLINSERTEVENTMARKEREXTPROC) gl3w__get_proc("glInsertEventMarkerEXT");
	gl3wInterpolatePathsNV = (PFNGLINTERPOLATEPATHSNVPROC) gl3w__get_proc("glInterpolatePathsNV");
	gl3wInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC) gl3w__get_proc("glInvalidateBufferData");
	gl3wInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC) gl3w__get_proc("glInvalidateBufferSubData");
	gl3wInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC) gl3w__get_proc("glInvalidateFramebuffer");
	gl3wInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) gl3w__get_proc("glInvalidateNamedFramebufferData");
	gl3wInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) gl3w__get_proc("glInvalidateNamedFramebufferSubData");
	gl3wInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC) gl3w__get_proc("glInvalidateSubFramebuffer");
	gl3wInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC) gl3w__get_proc("glInvalidateTexImage");
	gl3wInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC) gl3w__get_proc("glInvalidateTexSubImage");
	gl3wIsBuffer = (PFNGLISBUFFERPROC) gl3w__get_proc("glIsBuffer");
	gl3wIsBufferResidentNV = (PFNGLISBUFFERRESIDENTNVPROC) gl3w__get_proc("glIsBufferResidentNV");
	gl3wIsCommandListNV = (PFNGLISCOMMANDLISTNVPROC) gl3w__get_proc("glIsCommandListNV");
	gl3wIsEnabled = (PFNGLISENABLEDPROC) gl3w__get_proc("glIsEnabled");
	gl3wIsEnabledIndexedEXT = (PFNGLISENABLEDINDEXEDEXTPROC) gl3w__get_proc("glIsEnabledIndexedEXT");
	gl3wIsEnabledi = (PFNGLISENABLEDIPROC) gl3w__get_proc("glIsEnabledi");
	gl3wIsFramebuffer = (PFNGLISFRAMEBUFFERPROC) gl3w__get_proc("glIsFramebuffer");
	gl3wIsImageHandleResidentARB = (PFNGLISIMAGEHANDLERESIDENTARBPROC) gl3w__get_proc("glIsImageHandleResidentARB");
	gl3wIsImageHandleResidentNV = (PFNGLISIMAGEHANDLERESIDENTNVPROC) gl3w__get_proc("glIsImageHandleResidentNV");
	gl3wIsNamedBufferResidentNV = (PFNGLISNAMEDBUFFERRESIDENTNVPROC) gl3w__get_proc("glIsNamedBufferResidentNV");
	gl3wIsNamedStringARB = (PFNGLISNAMEDSTRINGARBPROC) gl3w__get_proc("glIsNamedStringARB");
	gl3wIsPathNV = (PFNGLISPATHNVPROC) gl3w__get_proc("glIsPathNV");
	gl3wIsPointInFillPathNV = (PFNGLISPOINTINFILLPATHNVPROC) gl3w__get_proc("glIsPointInFillPathNV");
	gl3wIsPointInStrokePathNV = (PFNGLISPOINTINSTROKEPATHNVPROC) gl3w__get_proc("glIsPointInStrokePathNV");
	gl3wIsProgram = (PFNGLISPROGRAMPROC) gl3w__get_proc("glIsProgram");
	gl3wIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC) gl3w__get_proc("glIsProgramPipeline");
	gl3wIsQuery = (PFNGLISQUERYPROC) gl3w__get_proc("glIsQuery");
	gl3wIsRenderbuffer = (PFNGLISRENDERBUFFERPROC) gl3w__get_proc("glIsRenderbuffer");
	gl3wIsSampler = (PFNGLISSAMPLERPROC) gl3w__get_proc("glIsSampler");
	gl3wIsShader = (PFNGLISSHADERPROC) gl3w__get_proc("glIsShader");
	gl3wIsStateNV = (PFNGLISSTATENVPROC) gl3w__get_proc("glIsStateNV");
	gl3wIsSync = (PFNGLISSYNCPROC) gl3w__get_proc("glIsSync");
	gl3wIsTexture = (PFNGLISTEXTUREPROC) gl3w__get_proc("glIsTexture");
	gl3wIsTextureHandleResidentARB = (PFNGLISTEXTUREHANDLERESIDENTARBPROC) gl3w__get_proc("glIsTextureHandleResidentARB");
	gl3wIsTextureHandleResidentNV = (PFNGLISTEXTUREHANDLERESIDENTNVPROC) gl3w__get_proc("glIsTextureHandleResidentNV");
	gl3wIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC) gl3w__get_proc("glIsTransformFeedback");
	gl3wIsVertexArray = (PFNGLISVERTEXARRAYPROC) gl3w__get_proc("glIsVertexArray");
	gl3wLabelObjectEXT = (PFNGLLABELOBJECTEXTPROC) gl3w__get_proc("glLabelObjectEXT");
	gl3wLineWidth = (PFNGLLINEWIDTHPROC) gl3w__get_proc("glLineWidth");
	gl3wLinkProgram = (PFNGLLINKPROGRAMPROC) gl3w__get_proc("glLinkProgram");
	gl3wListDrawCommandsStatesClientNV = (PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC) gl3w__get_proc("glListDrawCommandsStatesClientNV");
	gl3wLogicOp = (PFNGLLOGICOPPROC) gl3w__get_proc("glLogicOp");
	gl3wMakeBufferNonResidentNV = (PFNGLMAKEBUFFERNONRESIDENTNVPROC) gl3w__get_proc("glMakeBufferNonResidentNV");
	gl3wMakeBufferResidentNV = (PFNGLMAKEBUFFERRESIDENTNVPROC) gl3w__get_proc("glMakeBufferResidentNV");
	gl3wMakeImageHandleNonResidentARB = (PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC) gl3w__get_proc("glMakeImageHandleNonResidentARB");
	gl3wMakeImageHandleNonResidentNV = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC) gl3w__get_proc("glMakeImageHandleNonResidentNV");
	gl3wMakeImageHandleResidentARB = (PFNGLMAKEIMAGEHANDLERESIDENTARBPROC) gl3w__get_proc("glMakeImageHandleResidentARB");
	gl3wMakeImageHandleResidentNV = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC) gl3w__get_proc("glMakeImageHandleResidentNV");
	gl3wMakeNamedBufferNonResidentNV = (PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC) gl3w__get_proc("glMakeNamedBufferNonResidentNV");
	gl3wMakeNamedBufferResidentNV = (PFNGLMAKENAMEDBUFFERRESIDENTNVPROC) gl3w__get_proc("glMakeNamedBufferResidentNV");
	gl3wMakeTextureHandleNonResidentARB = (PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC) gl3w__get_proc("glMakeTextureHandleNonResidentARB");
	gl3wMakeTextureHandleNonResidentNV = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC) gl3w__get_proc("glMakeTextureHandleNonResidentNV");
	gl3wMakeTextureHandleResidentARB = (PFNGLMAKETEXTUREHANDLERESIDENTARBPROC) gl3w__get_proc("glMakeTextureHandleResidentARB");
	gl3wMakeTextureHandleResidentNV = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC) gl3w__get_proc("glMakeTextureHandleResidentNV");
	gl3wMapBuffer = (PFNGLMAPBUFFERPROC) gl3w__get_proc("glMapBuffer");
	gl3wMapBufferRange = (PFNGLMAPBUFFERRANGEPROC) gl3w__get_proc("glMapBufferRange");
	gl3wMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC) gl3w__get_proc("glMapNamedBuffer");
	gl3wMapNamedBufferEXT = (PFNGLMAPNAMEDBUFFEREXTPROC) gl3w__get_proc("glMapNamedBufferEXT");
	gl3wMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC) gl3w__get_proc("glMapNamedBufferRange");
	gl3wMapNamedBufferRangeEXT = (PFNGLMAPNAMEDBUFFERRANGEEXTPROC) gl3w__get_proc("glMapNamedBufferRangeEXT");
	gl3wMatrixFrustumEXT = (PFNGLMATRIXFRUSTUMEXTPROC) gl3w__get_proc("glMatrixFrustumEXT");
	gl3wMatrixLoad3x2fNV = (PFNGLMATRIXLOAD3X2FNVPROC) gl3w__get_proc("glMatrixLoad3x2fNV");
	gl3wMatrixLoad3x3fNV = (PFNGLMATRIXLOAD3X3FNVPROC) gl3w__get_proc("glMatrixLoad3x3fNV");
	gl3wMatrixLoadIdentityEXT = (PFNGLMATRIXLOADIDENTITYEXTPROC) gl3w__get_proc("glMatrixLoadIdentityEXT");
	gl3wMatrixLoadTranspose3x3fNV = (PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC) gl3w__get_proc("glMatrixLoadTranspose3x3fNV");
	gl3wMatrixLoadTransposedEXT = (PFNGLMATRIXLOADTRANSPOSEDEXTPROC) gl3w__get_proc("glMatrixLoadTransposedEXT");
	gl3wMatrixLoadTransposefEXT = (PFNGLMATRIXLOADTRANSPOSEFEXTPROC) gl3w__get_proc("glMatrixLoadTransposefEXT");
	gl3wMatrixLoaddEXT = (PFNGLMATRIXLOADDEXTPROC) gl3w__get_proc("glMatrixLoaddEXT");
	gl3wMatrixLoadfEXT = (PFNGLMATRIXLOADFEXTPROC) gl3w__get_proc("glMatrixLoadfEXT");
	gl3wMatrixMult3x2fNV = (PFNGLMATRIXMULT3X2FNVPROC) gl3w__get_proc("glMatrixMult3x2fNV");
	gl3wMatrixMult3x3fNV = (PFNGLMATRIXMULT3X3FNVPROC) gl3w__get_proc("glMatrixMult3x3fNV");
	gl3wMatrixMultTranspose3x3fNV = (PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC) gl3w__get_proc("glMatrixMultTranspose3x3fNV");
	gl3wMatrixMultTransposedEXT = (PFNGLMATRIXMULTTRANSPOSEDEXTPROC) gl3w__get_proc("glMatrixMultTransposedEXT");
	gl3wMatrixMultTransposefEXT = (PFNGLMATRIXMULTTRANSPOSEFEXTPROC) gl3w__get_proc("glMatrixMultTransposefEXT");
	gl3wMatrixMultdEXT = (PFNGLMATRIXMULTDEXTPROC) gl3w__get_proc("glMatrixMultdEXT");
	gl3wMatrixMultfEXT = (PFNGLMATRIXMULTFEXTPROC) gl3w__get_proc("glMatrixMultfEXT");
	gl3wMatrixOrthoEXT = (PFNGLMATRIXORTHOEXTPROC) gl3w__get_proc("glMatrixOrthoEXT");
	gl3wMatrixPopEXT = (PFNGLMATRIXPOPEXTPROC) gl3w__get_proc("glMatrixPopEXT");
	gl3wMatrixPushEXT = (PFNGLMATRIXPUSHEXTPROC) gl3w__get_proc("glMatrixPushEXT");
	gl3wMatrixRotatedEXT = (PFNGLMATRIXROTATEDEXTPROC) gl3w__get_proc("glMatrixRotatedEXT");
	gl3wMatrixRotatefEXT = (PFNGLMATRIXROTATEFEXTPROC) gl3w__get_proc("glMatrixRotatefEXT");
	gl3wMatrixScaledEXT = (PFNGLMATRIXSCALEDEXTPROC) gl3w__get_proc("glMatrixScaledEXT");
	gl3wMatrixScalefEXT = (PFNGLMATRIXSCALEFEXTPROC) gl3w__get_proc("glMatrixScalefEXT");
	gl3wMatrixTranslatedEXT = (PFNGLMATRIXTRANSLATEDEXTPROC) gl3w__get_proc("glMatrixTranslatedEXT");
	gl3wMatrixTranslatefEXT = (PFNGLMATRIXTRANSLATEFEXTPROC) gl3w__get_proc("glMatrixTranslatefEXT");
	gl3wMaxShaderCompilerThreadsARB = (PFNGLMAXSHADERCOMPILERTHREADSARBPROC) gl3w__get_proc("glMaxShaderCompilerThreadsARB");
	gl3wMaxShaderCompilerThreadsKHR = (PFNGLMAXSHADERCOMPILERTHREADSKHRPROC) gl3w__get_proc("glMaxShaderCompilerThreadsKHR");
	gl3wMemoryBarrier = (PFNGLMEMORYBARRIERPROC) gl3w__get_proc("glMemoryBarrier");
	gl3wMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC) gl3w__get_proc("glMemoryBarrierByRegion");
	gl3wMinSampleShading = (PFNGLMINSAMPLESHADINGPROC) gl3w__get_proc("glMinSampleShading");
	gl3wMinSampleShadingARB = (PFNGLMINSAMPLESHADINGARBPROC) gl3w__get_proc("glMinSampleShadingARB");
	gl3wMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC) gl3w__get_proc("glMultiDrawArrays");
	gl3wMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC) gl3w__get_proc("glMultiDrawArraysIndirect");
	gl3wMultiDrawArraysIndirectBindlessCountNV = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC) gl3w__get_proc("glMultiDrawArraysIndirectBindlessCountNV");
	gl3wMultiDrawArraysIndirectBindlessNV = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC) gl3w__get_proc("glMultiDrawArraysIndirectBindlessNV");
	gl3wMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC) gl3w__get_proc("glMultiDrawArraysIndirectCount");
	gl3wMultiDrawArraysIndirectCountARB = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC) gl3w__get_proc("glMultiDrawArraysIndirectCountARB");
	gl3wMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC) gl3w__get_proc("glMultiDrawElements");
	gl3wMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) gl3w__get_proc("glMultiDrawElementsBaseVertex");
	gl3wMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC) gl3w__get_proc("glMultiDrawElementsIndirect");
	gl3wMultiDrawElementsIndirectBindlessCountNV = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC) gl3w__get_proc("glMultiDrawElementsIndirectBindlessCountNV");
	gl3wMultiDrawElementsIndirectBindlessNV = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC) gl3w__get_proc("glMultiDrawElementsIndirectBindlessNV");
	gl3wMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) gl3w__get_proc("glMultiDrawElementsIndirectCount");
	gl3wMultiDrawElementsIndirectCountARB = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC) gl3w__get_proc("glMultiDrawElementsIndirectCountARB");
	gl3wMultiTexBufferEXT = (PFNGLMULTITEXBUFFEREXTPROC) gl3w__get_proc("glMultiTexBufferEXT");
	gl3wMultiTexCoordPointerEXT = (PFNGLMULTITEXCOORDPOINTEREXTPROC) gl3w__get_proc("glMultiTexCoordPointerEXT");
	gl3wMultiTexEnvfEXT = (PFNGLMULTITEXENVFEXTPROC) gl3w__get_proc("glMultiTexEnvfEXT");
	gl3wMultiTexEnvfvEXT = (PFNGLMULTITEXENVFVEXTPROC) gl3w__get_proc("glMultiTexEnvfvEXT");
	gl3wMultiTexEnviEXT = (PFNGLMULTITEXENVIEXTPROC) gl3w__get_proc("glMultiTexEnviEXT");
	gl3wMultiTexEnvivEXT = (PFNGLMULTITEXENVIVEXTPROC) gl3w__get_proc("glMultiTexEnvivEXT");
	gl3wMultiTexGendEXT = (PFNGLMULTITEXGENDEXTPROC) gl3w__get_proc("glMultiTexGendEXT");
	gl3wMultiTexGendvEXT = (PFNGLMULTITEXGENDVEXTPROC) gl3w__get_proc("glMultiTexGendvEXT");
	gl3wMultiTexGenfEXT = (PFNGLMULTITEXGENFEXTPROC) gl3w__get_proc("glMultiTexGenfEXT");
	gl3wMultiTexGenfvEXT = (PFNGLMULTITEXGENFVEXTPROC) gl3w__get_proc("glMultiTexGenfvEXT");
	gl3wMultiTexGeniEXT = (PFNGLMULTITEXGENIEXTPROC) gl3w__get_proc("glMultiTexGeniEXT");
	gl3wMultiTexGenivEXT = (PFNGLMULTITEXGENIVEXTPROC) gl3w__get_proc("glMultiTexGenivEXT");
	gl3wMultiTexImage1DEXT = (PFNGLMULTITEXIMAGE1DEXTPROC) gl3w__get_proc("glMultiTexImage1DEXT");
	gl3wMultiTexImage2DEXT = (PFNGLMULTITEXIMAGE2DEXTPROC) gl3w__get_proc("glMultiTexImage2DEXT");
	gl3wMultiTexImage3DEXT = (PFNGLMULTITEXIMAGE3DEXTPROC) gl3w__get_proc("glMultiTexImage3DEXT");
	gl3wMultiTexParameterIivEXT = (PFNGLMULTITEXPARAMETERIIVEXTPROC) gl3w__get_proc("glMultiTexParameterIivEXT");
	gl3wMultiTexParameterIuivEXT = (PFNGLMULTITEXPARAMETERIUIVEXTPROC) gl3w__get_proc("glMultiTexParameterIuivEXT");
	gl3wMultiTexParameterfEXT = (PFNGLMULTITEXPARAMETERFEXTPROC) gl3w__get_proc("glMultiTexParameterfEXT");
	gl3wMultiTexParameterfvEXT = (PFNGLMULTITEXPARAMETERFVEXTPROC) gl3w__get_proc("glMultiTexParameterfvEXT");
	gl3wMultiTexParameteriEXT = (PFNGLMULTITEXPARAMETERIEXTPROC) gl3w__get_proc("glMultiTexParameteriEXT");
	gl3wMultiTexParameterivEXT = (PFNGLMULTITEXPARAMETERIVEXTPROC) gl3w__get_proc("glMultiTexParameterivEXT");
	gl3wMultiTexRenderbufferEXT = (PFNGLMULTITEXRENDERBUFFEREXTPROC) gl3w__get_proc("glMultiTexRenderbufferEXT");
	gl3wMultiTexSubImage1DEXT = (PFNGLMULTITEXSUBIMAGE1DEXTPROC) gl3w__get_proc("glMultiTexSubImage1DEXT");
	gl3wMultiTexSubImage2DEXT = (PFNGLMULTITEXSUBIMAGE2DEXTPROC) gl3w__get_proc("glMultiTexSubImage2DEXT");
	gl3wMultiTexSubImage3DEXT = (PFNGLMULTITEXSUBIMAGE3DEXTPROC) gl3w__get_proc("glMultiTexSubImage3DEXT");
	gl3wNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC) gl3w__get_proc("glNamedBufferData");
	gl3wNamedBufferDataEXT = (PFNGLNAMEDBUFFERDATAEXTPROC) gl3w__get_proc("glNamedBufferDataEXT");
	gl3wNamedBufferPageCommitmentARB = (PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC) gl3w__get_proc("glNamedBufferPageCommitmentARB");
	gl3wNamedBufferPageCommitmentEXT = (PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC) gl3w__get_proc("glNamedBufferPageCommitmentEXT");
	gl3wNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC) gl3w__get_proc("glNamedBufferStorage");
	gl3wNamedBufferStorageEXT = (PFNGLNAMEDBUFFERSTORAGEEXTPROC) gl3w__get_proc("glNamedBufferStorageEXT");
	gl3wNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC) gl3w__get_proc("glNamedBufferSubData");
	gl3wNamedBufferSubDataEXT = (PFNGLNAMEDBUFFERSUBDATAEXTPROC) gl3w__get_proc("glNamedBufferSubDataEXT");
	gl3wNamedCopyBufferSubDataEXT = (PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC) gl3w__get_proc("glNamedCopyBufferSubDataEXT");
	gl3wNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) gl3w__get_proc("glNamedFramebufferDrawBuffer");
	gl3wNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) gl3w__get_proc("glNamedFramebufferDrawBuffers");
	gl3wNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) gl3w__get_proc("glNamedFramebufferParameteri");
	gl3wNamedFramebufferParameteriEXT = (PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC) gl3w__get_proc("glNamedFramebufferParameteriEXT");
	gl3wNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) gl3w__get_proc("glNamedFramebufferReadBuffer");
	gl3wNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) gl3w__get_proc("glNamedFramebufferRenderbuffer");
	gl3wNamedFramebufferRenderbufferEXT = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC) gl3w__get_proc("glNamedFramebufferRenderbufferEXT");
	gl3wNamedFramebufferSampleLocationsfvARB = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC) gl3w__get_proc("glNamedFramebufferSampleLocationsfvARB");
	gl3wNamedFramebufferSampleLocationsfvNV = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC) gl3w__get_proc("glNamedFramebufferSampleLocationsfvNV");
	gl3wNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) gl3w__get_proc("glNamedFramebufferTexture");
	gl3wNamedFramebufferTexture1DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC) gl3w__get_proc("glNamedFramebufferTexture1DEXT");
	gl3wNamedFramebufferTexture2DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC) gl3w__get_proc("glNamedFramebufferTexture2DEXT");
	gl3wNamedFramebufferTexture3DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC) gl3w__get_proc("glNamedFramebufferTexture3DEXT");
	gl3wNamedFramebufferTextureEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC) gl3w__get_proc("glNamedFramebufferTextureEXT");
	gl3wNamedFramebufferTextureFaceEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC) gl3w__get_proc("glNamedFramebufferTextureFaceEXT");
	gl3wNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) gl3w__get_proc("glNamedFramebufferTextureLayer");
	gl3wNamedFramebufferTextureLayerEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC) gl3w__get_proc("glNamedFramebufferTextureLayerEXT");
	gl3wNamedProgramLocalParameter4dEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC) gl3w__get_proc("glNamedProgramLocalParameter4dEXT");
	gl3wNamedProgramLocalParameter4dvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC) gl3w__get_proc("glNamedProgramLocalParameter4dvEXT");
	gl3wNamedProgramLocalParameter4fEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC) gl3w__get_proc("glNamedProgramLocalParameter4fEXT");
	gl3wNamedProgramLocalParameter4fvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC) gl3w__get_proc("glNamedProgramLocalParameter4fvEXT");
	gl3wNamedProgramLocalParameterI4iEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC) gl3w__get_proc("glNamedProgramLocalParameterI4iEXT");
	gl3wNamedProgramLocalParameterI4ivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC) gl3w__get_proc("glNamedProgramLocalParameterI4ivEXT");
	gl3wNamedProgramLocalParameterI4uiEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC) gl3w__get_proc("glNamedProgramLocalParameterI4uiEXT");
	gl3wNamedProgramLocalParameterI4uivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC) gl3w__get_proc("glNamedProgramLocalParameterI4uivEXT");
	gl3wNamedProgramLocalParameters4fvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC) gl3w__get_proc("glNamedProgramLocalParameters4fvEXT");
	gl3wNamedProgramLocalParametersI4ivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC) gl3w__get_proc("glNamedProgramLocalParametersI4ivEXT");
	gl3wNamedProgramLocalParametersI4uivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC) gl3w__get_proc("glNamedProgramLocalParametersI4uivEXT");
	gl3wNamedProgramStringEXT = (PFNGLNAMEDPROGRAMSTRINGEXTPROC) gl3w__get_proc("glNamedProgramStringEXT");
	gl3wNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC) gl3w__get_proc("glNamedRenderbufferStorage");
	gl3wNamedRenderbufferStorageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC) gl3w__get_proc("glNamedRenderbufferStorageEXT");
	gl3wNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) gl3w__get_proc("glNamedRenderbufferStorageMultisample");
	gl3wNamedRenderbufferStorageMultisampleCoverageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC) gl3w__get_proc("glNamedRenderbufferStorageMultisampleCoverageEXT");
	gl3wNamedRenderbufferStorageMultisampleEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) gl3w__get_proc("glNamedRenderbufferStorageMultisampleEXT");
	gl3wNamedStringARB = (PFNGLNAMEDSTRINGARBPROC) gl3w__get_proc("glNamedStringARB");
	gl3wNormalFormatNV = (PFNGLNORMALFORMATNVPROC) gl3w__get_proc("glNormalFormatNV");
	gl3wObjectLabel = (PFNGLOBJECTLABELPROC) gl3w__get_proc("glObjectLabel");
	gl3wObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC) gl3w__get_proc("glObjectPtrLabel");
	gl3wPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC) gl3w__get_proc("glPatchParameterfv");
	gl3wPatchParameteri = (PFNGLPATCHPARAMETERIPROC) gl3w__get_proc("glPatchParameteri");
	gl3wPathCommandsNV = (PFNGLPATHCOMMANDSNVPROC) gl3w__get_proc("glPathCommandsNV");
	gl3wPathCoordsNV = (PFNGLPATHCOORDSNVPROC) gl3w__get_proc("glPathCoordsNV");
	gl3wPathCoverDepthFuncNV = (PFNGLPATHCOVERDEPTHFUNCNVPROC) gl3w__get_proc("glPathCoverDepthFuncNV");
	gl3wPathDashArrayNV = (PFNGLPATHDASHARRAYNVPROC) gl3w__get_proc("glPathDashArrayNV");
	gl3wPathGlyphIndexArrayNV = (PFNGLPATHGLYPHINDEXARRAYNVPROC) gl3w__get_proc("glPathGlyphIndexArrayNV");
	gl3wPathGlyphIndexRangeNV = (PFNGLPATHGLYPHINDEXRANGENVPROC) gl3w__get_proc("glPathGlyphIndexRangeNV");
	gl3wPathGlyphRangeNV = (PFNGLPATHGLYPHRANGENVPROC) gl3w__get_proc("glPathGlyphRangeNV");
	gl3wPathGlyphsNV = (PFNGLPATHGLYPHSNVPROC) gl3w__get_proc("glPathGlyphsNV");
	gl3wPathMemoryGlyphIndexArrayNV = (PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC) gl3w__get_proc("glPathMemoryGlyphIndexArrayNV");
	gl3wPathParameterfNV = (PFNGLPATHPARAMETERFNVPROC) gl3w__get_proc("glPathParameterfNV");
	gl3wPathParameterfvNV = (PFNGLPATHPARAMETERFVNVPROC) gl3w__get_proc("glPathParameterfvNV");
	gl3wPathParameteriNV = (PFNGLPATHPARAMETERINVPROC) gl3w__get_proc("glPathParameteriNV");
	gl3wPathParameterivNV = (PFNGLPATHPARAMETERIVNVPROC) gl3w__get_proc("glPathParameterivNV");
	gl3wPathStencilDepthOffsetNV = (PFNGLPATHSTENCILDEPTHOFFSETNVPROC) gl3w__get_proc("glPathStencilDepthOffsetNV");
	gl3wPathStencilFuncNV = (PFNGLPATHSTENCILFUNCNVPROC) gl3w__get_proc("glPathStencilFuncNV");
	gl3wPathStringNV = (PFNGLPATHSTRINGNVPROC) gl3w__get_proc("glPathStringNV");
	gl3wPathSubCommandsNV = (PFNGLPATHSUBCOMMANDSNVPROC) gl3w__get_proc("glPathSubCommandsNV");
	gl3wPathSubCoordsNV = (PFNGLPATHSUBCOORDSNVPROC) gl3w__get_proc("glPathSubCoordsNV");
	gl3wPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC) gl3w__get_proc("glPauseTransformFeedback");
	gl3wPixelStoref = (PFNGLPIXELSTOREFPROC) gl3w__get_proc("glPixelStoref");
	gl3wPixelStorei = (PFNGLPIXELSTOREIPROC) gl3w__get_proc("glPixelStorei");
	gl3wPointAlongPathNV = (PFNGLPOINTALONGPATHNVPROC) gl3w__get_proc("glPointAlongPathNV");
	gl3wPointParameterf = (PFNGLPOINTPARAMETERFPROC) gl3w__get_proc("glPointParameterf");
	gl3wPointParameterfv = (PFNGLPOINTPARAMETERFVPROC) gl3w__get_proc("glPointParameterfv");
	gl3wPointParameteri = (PFNGLPOINTPARAMETERIPROC) gl3w__get_proc("glPointParameteri");
	gl3wPointParameteriv = (PFNGLPOINTPARAMETERIVPROC) gl3w__get_proc("glPointParameteriv");
	gl3wPointSize = (PFNGLPOINTSIZEPROC) gl3w__get_proc("glPointSize");
	gl3wPolygonMode = (PFNGLPOLYGONMODEPROC) gl3w__get_proc("glPolygonMode");
	gl3wPolygonOffset = (PFNGLPOLYGONOFFSETPROC) gl3w__get_proc("glPolygonOffset");
	gl3wPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC) gl3w__get_proc("glPolygonOffsetClamp");
	gl3wPolygonOffsetClampEXT = (PFNGLPOLYGONOFFSETCLAMPEXTPROC) gl3w__get_proc("glPolygonOffsetClampEXT");
	gl3wPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC) gl3w__get_proc("glPopDebugGroup");
	gl3wPopGroupMarkerEXT = (PFNGLPOPGROUPMARKEREXTPROC) gl3w__get_proc("glPopGroupMarkerEXT");
	gl3wPrimitiveBoundingBoxARB = (PFNGLPRIMITIVEBOUNDINGBOXARBPROC) gl3w__get_proc("glPrimitiveBoundingBoxARB");
	gl3wPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC) gl3w__get_proc("glPrimitiveRestartIndex");
	gl3wProgramBinary = (PFNGLPROGRAMBINARYPROC) gl3w__get_proc("glProgramBinary");
	gl3wProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC) gl3w__get_proc("glProgramParameteri");
	gl3wProgramParameteriARB = (PFNGLPROGRAMPARAMETERIARBPROC) gl3w__get_proc("glProgramParameteriARB");
	gl3wProgramPathFragmentInputGenNV = (PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC) gl3w__get_proc("glProgramPathFragmentInputGenNV");
	gl3wProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC) gl3w__get_proc("glProgramUniform1d");
	gl3wProgramUniform1dEXT = (PFNGLPROGRAMUNIFORM1DEXTPROC) gl3w__get_proc("glProgramUniform1dEXT");
	gl3wProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC) gl3w__get_proc("glProgramUniform1dv");
	gl3wProgramUniform1dvEXT = (PFNGLPROGRAMUNIFORM1DVEXTPROC) gl3w__get_proc("glProgramUniform1dvEXT");
	gl3wProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC) gl3w__get_proc("glProgramUniform1f");
	gl3wProgramUniform1fEXT = (PFNGLPROGRAMUNIFORM1FEXTPROC) gl3w__get_proc("glProgramUniform1fEXT");
	gl3wProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC) gl3w__get_proc("glProgramUniform1fv");
	gl3wProgramUniform1fvEXT = (PFNGLPROGRAMUNIFORM1FVEXTPROC) gl3w__get_proc("glProgramUniform1fvEXT");
	gl3wProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC) gl3w__get_proc("glProgramUniform1i");
	gl3wProgramUniform1i64ARB = (PFNGLPROGRAMUNIFORM1I64ARBPROC) gl3w__get_proc("glProgramUniform1i64ARB");
	gl3wProgramUniform1i64NV = (PFNGLPROGRAMUNIFORM1I64NVPROC) gl3w__get_proc("glProgramUniform1i64NV");
	gl3wProgramUniform1i64vARB = (PFNGLPROGRAMUNIFORM1I64VARBPROC) gl3w__get_proc("glProgramUniform1i64vARB");
	gl3wProgramUniform1i64vNV = (PFNGLPROGRAMUNIFORM1I64VNVPROC) gl3w__get_proc("glProgramUniform1i64vNV");
	gl3wProgramUniform1iEXT = (PFNGLPROGRAMUNIFORM1IEXTPROC) gl3w__get_proc("glProgramUniform1iEXT");
	gl3wProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC) gl3w__get_proc("glProgramUniform1iv");
	gl3wProgramUniform1ivEXT = (PFNGLPROGRAMUNIFORM1IVEXTPROC) gl3w__get_proc("glProgramUniform1ivEXT");
	gl3wProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC) gl3w__get_proc("glProgramUniform1ui");
	gl3wProgramUniform1ui64ARB = (PFNGLPROGRAMUNIFORM1UI64ARBPROC) gl3w__get_proc("glProgramUniform1ui64ARB");
	gl3wProgramUniform1ui64NV = (PFNGLPROGRAMUNIFORM1UI64NVPROC) gl3w__get_proc("glProgramUniform1ui64NV");
	gl3wProgramUniform1ui64vARB = (PFNGLPROGRAMUNIFORM1UI64VARBPROC) gl3w__get_proc("glProgramUniform1ui64vARB");
	gl3wProgramUniform1ui64vNV = (PFNGLPROGRAMUNIFORM1UI64VNVPROC) gl3w__get_proc("glProgramUniform1ui64vNV");
	gl3wProgramUniform1uiEXT = (PFNGLPROGRAMUNIFORM1UIEXTPROC) gl3w__get_proc("glProgramUniform1uiEXT");
	gl3wProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC) gl3w__get_proc("glProgramUniform1uiv");
	gl3wProgramUniform1uivEXT = (PFNGLPROGRAMUNIFORM1UIVEXTPROC) gl3w__get_proc("glProgramUniform1uivEXT");
	gl3wProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC) gl3w__get_proc("glProgramUniform2d");
	gl3wProgramUniform2dEXT = (PFNGLPROGRAMUNIFORM2DEXTPROC) gl3w__get_proc("glProgramUniform2dEXT");
	gl3wProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC) gl3w__get_proc("glProgramUniform2dv");
	gl3wProgramUniform2dvEXT = (PFNGLPROGRAMUNIFORM2DVEXTPROC) gl3w__get_proc("glProgramUniform2dvEXT");
	gl3wProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC) gl3w__get_proc("glProgramUniform2f");
	gl3wProgramUniform2fEXT = (PFNGLPROGRAMUNIFORM2FEXTPROC) gl3w__get_proc("glProgramUniform2fEXT");
	gl3wProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC) gl3w__get_proc("glProgramUniform2fv");
	gl3wProgramUniform2fvEXT = (PFNGLPROGRAMUNIFORM2FVEXTPROC) gl3w__get_proc("glProgramUniform2fvEXT");
	gl3wProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC) gl3w__get_proc("glProgramUniform2i");
	gl3wProgramUniform2i64ARB = (PFNGLPROGRAMUNIFORM2I64ARBPROC) gl3w__get_proc("glProgramUniform2i64ARB");
	gl3wProgramUniform2i64NV = (PFNGLPROGRAMUNIFORM2I64NVPROC) gl3w__get_proc("glProgramUniform2i64NV");
	gl3wProgramUniform2i64vARB = (PFNGLPROGRAMUNIFORM2I64VARBPROC) gl3w__get_proc("glProgramUniform2i64vARB");
	gl3wProgramUniform2i64vNV = (PFNGLPROGRAMUNIFORM2I64VNVPROC) gl3w__get_proc("glProgramUniform2i64vNV");
	gl3wProgramUniform2iEXT = (PFNGLPROGRAMUNIFORM2IEXTPROC) gl3w__get_proc("glProgramUniform2iEXT");
	gl3wProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC) gl3w__get_proc("glProgramUniform2iv");
	gl3wProgramUniform2ivEXT = (PFNGLPROGRAMUNIFORM2IVEXTPROC) gl3w__get_proc("glProgramUniform2ivEXT");
	gl3wProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC) gl3w__get_proc("glProgramUniform2ui");
	gl3wProgramUniform2ui64ARB = (PFNGLPROGRAMUNIFORM2UI64ARBPROC) gl3w__get_proc("glProgramUniform2ui64ARB");
	gl3wProgramUniform2ui64NV = (PFNGLPROGRAMUNIFORM2UI64NVPROC) gl3w__get_proc("glProgramUniform2ui64NV");
	gl3wProgramUniform2ui64vARB = (PFNGLPROGRAMUNIFORM2UI64VARBPROC) gl3w__get_proc("glProgramUniform2ui64vARB");
	gl3wProgramUniform2ui64vNV = (PFNGLPROGRAMUNIFORM2UI64VNVPROC) gl3w__get_proc("glProgramUniform2ui64vNV");
	gl3wProgramUniform2uiEXT = (PFNGLPROGRAMUNIFORM2UIEXTPROC) gl3w__get_proc("glProgramUniform2uiEXT");
	gl3wProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC) gl3w__get_proc("glProgramUniform2uiv");
	gl3wProgramUniform2uivEXT = (PFNGLPROGRAMUNIFORM2UIVEXTPROC) gl3w__get_proc("glProgramUniform2uivEXT");
	gl3wProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC) gl3w__get_proc("glProgramUniform3d");
	gl3wProgramUniform3dEXT = (PFNGLPROGRAMUNIFORM3DEXTPROC) gl3w__get_proc("glProgramUniform3dEXT");
	gl3wProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC) gl3w__get_proc("glProgramUniform3dv");
	gl3wProgramUniform3dvEXT = (PFNGLPROGRAMUNIFORM3DVEXTPROC) gl3w__get_proc("glProgramUniform3dvEXT");
	gl3wProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC) gl3w__get_proc("glProgramUniform3f");
	gl3wProgramUniform3fEXT = (PFNGLPROGRAMUNIFORM3FEXTPROC) gl3w__get_proc("glProgramUniform3fEXT");
	gl3wProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC) gl3w__get_proc("glProgramUniform3fv");
	gl3wProgramUniform3fvEXT = (PFNGLPROGRAMUNIFORM3FVEXTPROC) gl3w__get_proc("glProgramUniform3fvEXT");
	gl3wProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC) gl3w__get_proc("glProgramUniform3i");
	gl3wProgramUniform3i64ARB = (PFNGLPROGRAMUNIFORM3I64ARBPROC) gl3w__get_proc("glProgramUniform3i64ARB");
	gl3wProgramUniform3i64NV = (PFNGLPROGRAMUNIFORM3I64NVPROC) gl3w__get_proc("glProgramUniform3i64NV");
	gl3wProgramUniform3i64vARB = (PFNGLPROGRAMUNIFORM3I64VARBPROC) gl3w__get_proc("glProgramUniform3i64vARB");
	gl3wProgramUniform3i64vNV = (PFNGLPROGRAMUNIFORM3I64VNVPROC) gl3w__get_proc("glProgramUniform3i64vNV");
	gl3wProgramUniform3iEXT = (PFNGLPROGRAMUNIFORM3IEXTPROC) gl3w__get_proc("glProgramUniform3iEXT");
	gl3wProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC) gl3w__get_proc("glProgramUniform3iv");
	gl3wProgramUniform3ivEXT = (PFNGLPROGRAMUNIFORM3IVEXTPROC) gl3w__get_proc("glProgramUniform3ivEXT");
	gl3wProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC) gl3w__get_proc("glProgramUniform3ui");
	gl3wProgramUniform3ui64ARB = (PFNGLPROGRAMUNIFORM3UI64ARBPROC) gl3w__get_proc("glProgramUniform3ui64ARB");
	gl3wProgramUniform3ui64NV = (PFNGLPROGRAMUNIFORM3UI64NVPROC) gl3w__get_proc("glProgramUniform3ui64NV");
	gl3wProgramUniform3ui64vARB = (PFNGLPROGRAMUNIFORM3UI64VARBPROC) gl3w__get_proc("glProgramUniform3ui64vARB");
	gl3wProgramUniform3ui64vNV = (PFNGLPROGRAMUNIFORM3UI64VNVPROC) gl3w__get_proc("glProgramUniform3ui64vNV");
	gl3wProgramUniform3uiEXT = (PFNGLPROGRAMUNIFORM3UIEXTPROC) gl3w__get_proc("glProgramUniform3uiEXT");
	gl3wProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC) gl3w__get_proc("glProgramUniform3uiv");
	gl3wProgramUniform3uivEXT = (PFNGLPROGRAMUNIFORM3UIVEXTPROC) gl3w__get_proc("glProgramUniform3uivEXT");
	gl3wProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC) gl3w__get_proc("glProgramUniform4d");
	gl3wProgramUniform4dEXT = (PFNGLPROGRAMUNIFORM4DEXTPROC) gl3w__get_proc("glProgramUniform4dEXT");
	gl3wProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC) gl3w__get_proc("glProgramUniform4dv");
	gl3wProgramUniform4dvEXT = (PFNGLPROGRAMUNIFORM4DVEXTPROC) gl3w__get_proc("glProgramUniform4dvEXT");
	gl3wProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC) gl3w__get_proc("glProgramUniform4f");
	gl3wProgramUniform4fEXT = (PFNGLPROGRAMUNIFORM4FEXTPROC) gl3w__get_proc("glProgramUniform4fEXT");
	gl3wProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC) gl3w__get_proc("glProgramUniform4fv");
	gl3wProgramUniform4fvEXT = (PFNGLPROGRAMUNIFORM4FVEXTPROC) gl3w__get_proc("glProgramUniform4fvEXT");
	gl3wProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC) gl3w__get_proc("glProgramUniform4i");
	gl3wProgramUniform4i64ARB = (PFNGLPROGRAMUNIFORM4I64ARBPROC) gl3w__get_proc("glProgramUniform4i64ARB");
	gl3wProgramUniform4i64NV = (PFNGLPROGRAMUNIFORM4I64NVPROC) gl3w__get_proc("glProgramUniform4i64NV");
	gl3wProgramUniform4i64vARB = (PFNGLPROGRAMUNIFORM4I64VARBPROC) gl3w__get_proc("glProgramUniform4i64vARB");
	gl3wProgramUniform4i64vNV = (PFNGLPROGRAMUNIFORM4I64VNVPROC) gl3w__get_proc("glProgramUniform4i64vNV");
	gl3wProgramUniform4iEXT = (PFNGLPROGRAMUNIFORM4IEXTPROC) gl3w__get_proc("glProgramUniform4iEXT");
	gl3wProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC) gl3w__get_proc("glProgramUniform4iv");
	gl3wProgramUniform4ivEXT = (PFNGLPROGRAMUNIFORM4IVEXTPROC) gl3w__get_proc("glProgramUniform4ivEXT");
	gl3wProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC) gl3w__get_proc("glProgramUniform4ui");
	gl3wProgramUniform4ui64ARB = (PFNGLPROGRAMUNIFORM4UI64ARBPROC) gl3w__get_proc("glProgramUniform4ui64ARB");
	gl3wProgramUniform4ui64NV = (PFNGLPROGRAMUNIFORM4UI64NVPROC) gl3w__get_proc("glProgramUniform4ui64NV");
	gl3wProgramUniform4ui64vARB = (PFNGLPROGRAMUNIFORM4UI64VARBPROC) gl3w__get_proc("glProgramUniform4ui64vARB");
	gl3wProgramUniform4ui64vNV = (PFNGLPROGRAMUNIFORM4UI64VNVPROC) gl3w__get_proc("glProgramUniform4ui64vNV");
	gl3wProgramUniform4uiEXT = (PFNGLPROGRAMUNIFORM4UIEXTPROC) gl3w__get_proc("glProgramUniform4uiEXT");
	gl3wProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC) gl3w__get_proc("glProgramUniform4uiv");
	gl3wProgramUniform4uivEXT = (PFNGLPROGRAMUNIFORM4UIVEXTPROC) gl3w__get_proc("glProgramUniform4uivEXT");
	gl3wProgramUniformHandleui64ARB = (PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC) gl3w__get_proc("glProgramUniformHandleui64ARB");
	gl3wProgramUniformHandleui64NV = (PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC) gl3w__get_proc("glProgramUniformHandleui64NV");
	gl3wProgramUniformHandleui64vARB = (PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC) gl3w__get_proc("glProgramUniformHandleui64vARB");
	gl3wProgramUniformHandleui64vNV = (PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC) gl3w__get_proc("glProgramUniformHandleui64vNV");
	gl3wProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC) gl3w__get_proc("glProgramUniformMatrix2dv");
	gl3wProgramUniformMatrix2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix2dvEXT");
	gl3wProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC) gl3w__get_proc("glProgramUniformMatrix2fv");
	gl3wProgramUniformMatrix2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix2fvEXT");
	gl3wProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) gl3w__get_proc("glProgramUniformMatrix2x3dv");
	gl3wProgramUniformMatrix2x3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix2x3dvEXT");
	gl3wProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) gl3w__get_proc("glProgramUniformMatrix2x3fv");
	gl3wProgramUniformMatrix2x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix2x3fvEXT");
	gl3wProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) gl3w__get_proc("glProgramUniformMatrix2x4dv");
	gl3wProgramUniformMatrix2x4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix2x4dvEXT");
	gl3wProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) gl3w__get_proc("glProgramUniformMatrix2x4fv");
	gl3wProgramUniformMatrix2x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix2x4fvEXT");
	gl3wProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC) gl3w__get_proc("glProgramUniformMatrix3dv");
	gl3wProgramUniformMatrix3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix3dvEXT");
	gl3wProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC) gl3w__get_proc("glProgramUniformMatrix3fv");
	gl3wProgramUniformMatrix3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix3fvEXT");
	gl3wProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) gl3w__get_proc("glProgramUniformMatrix3x2dv");
	gl3wProgramUniformMatrix3x2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix3x2dvEXT");
	gl3wProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) gl3w__get_proc("glProgramUniformMatrix3x2fv");
	gl3wProgramUniformMatrix3x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix3x2fvEXT");
	gl3wProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) gl3w__get_proc("glProgramUniformMatrix3x4dv");
	gl3wProgramUniformMatrix3x4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix3x4dvEXT");
	gl3wProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) gl3w__get_proc("glProgramUniformMatrix3x4fv");
	gl3wProgramUniformMatrix3x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix3x4fvEXT");
	gl3wProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC) gl3w__get_proc("glProgramUniformMatrix4dv");
	gl3wProgramUniformMatrix4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix4dvEXT");
	gl3wProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC) gl3w__get_proc("glProgramUniformMatrix4fv");
	gl3wProgramUniformMatrix4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix4fvEXT");
	gl3wProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) gl3w__get_proc("glProgramUniformMatrix4x2dv");
	gl3wProgramUniformMatrix4x2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix4x2dvEXT");
	gl3wProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) gl3w__get_proc("glProgramUniformMatrix4x2fv");
	gl3wProgramUniformMatrix4x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix4x2fvEXT");
	gl3wProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) gl3w__get_proc("glProgramUniformMatrix4x3dv");
	gl3wProgramUniformMatrix4x3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC) gl3w__get_proc("glProgramUniformMatrix4x3dvEXT");
	gl3wProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) gl3w__get_proc("glProgramUniformMatrix4x3fv");
	gl3wProgramUniformMatrix4x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC) gl3w__get_proc("glProgramUniformMatrix4x3fvEXT");
	gl3wProgramUniformui64NV = (PFNGLPROGRAMUNIFORMUI64NVPROC) gl3w__get_proc("glProgramUniformui64NV");
	gl3wProgramUniformui64vNV = (PFNGLPROGRAMUNIFORMUI64VNVPROC) gl3w__get_proc("glProgramUniformui64vNV");
	gl3wProvokingVertex = (PFNGLPROVOKINGVERTEXPROC) gl3w__get_proc("glProvokingVertex");
	gl3wPushClientAttribDefaultEXT = (PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC) gl3w__get_proc("glPushClientAttribDefaultEXT");
	gl3wPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC) gl3w__get_proc("glPushDebugGroup");
	gl3wPushGroupMarkerEXT = (PFNGLPUSHGROUPMARKEREXTPROC) gl3w__get_proc("glPushGroupMarkerEXT");
	gl3wQueryCounter = (PFNGLQUERYCOUNTERPROC) gl3w__get_proc("glQueryCounter");
	gl3wRasterSamplesEXT = (PFNGLRASTERSAMPLESEXTPROC) gl3w__get_proc("glRasterSamplesEXT");
	gl3wReadBuffer = (PFNGLREADBUFFERPROC) gl3w__get_proc("glReadBuffer");
	gl3wReadPixels = (PFNGLREADPIXELSPROC) gl3w__get_proc("glReadPixels");
	gl3wReadnPixels = (PFNGLREADNPIXELSPROC) gl3w__get_proc("glReadnPixels");
	gl3wReadnPixelsARB = (PFNGLREADNPIXELSARBPROC) gl3w__get_proc("glReadnPixelsARB");
	gl3wReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC) gl3w__get_proc("glReleaseShaderCompiler");
	gl3wRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC) gl3w__get_proc("glRenderbufferStorage");
	gl3wRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) gl3w__get_proc("glRenderbufferStorageMultisample");
	gl3wRenderbufferStorageMultisampleCoverageNV = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC) gl3w__get_proc("glRenderbufferStorageMultisampleCoverageNV");
	gl3wResolveDepthValuesNV = (PFNGLRESOLVEDEPTHVALUESNVPROC) gl3w__get_proc("glResolveDepthValuesNV");
	gl3wResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC) gl3w__get_proc("glResumeTransformFeedback");
	gl3wSampleCoverage = (PFNGLSAMPLECOVERAGEPROC) gl3w__get_proc("glSampleCoverage");
	gl3wSampleMaski = (PFNGLSAMPLEMASKIPROC) gl3w__get_proc("glSampleMaski");
	gl3wSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC) gl3w__get_proc("glSamplerParameterIiv");
	gl3wSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC) gl3w__get_proc("glSamplerParameterIuiv");
	gl3wSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC) gl3w__get_proc("glSamplerParameterf");
	gl3wSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC) gl3w__get_proc("glSamplerParameterfv");
	gl3wSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC) gl3w__get_proc("glSamplerParameteri");
	gl3wSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC) gl3w__get_proc("glSamplerParameteriv");
	gl3wScissor = (PFNGLSCISSORPROC) gl3w__get_proc("glScissor");
	gl3wScissorArrayv = (PFNGLSCISSORARRAYVPROC) gl3w__get_proc("glScissorArrayv");
	gl3wScissorIndexed = (PFNGLSCISSORINDEXEDPROC) gl3w__get_proc("glScissorIndexed");
	gl3wScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC) gl3w__get_proc("glScissorIndexedv");
	gl3wSecondaryColorFormatNV = (PFNGLSECONDARYCOLORFORMATNVPROC) gl3w__get_proc("glSecondaryColorFormatNV");
	gl3wSelectPerfMonitorCountersAMD = (PFNGLSELECTPERFMONITORCOUNTERSAMDPROC) gl3w__get_proc("glSelectPerfMonitorCountersAMD");
	gl3wShaderBinary = (PFNGLSHADERBINARYPROC) gl3w__get_proc("glShaderBinary");
	gl3wShaderSource = (PFNGLSHADERSOURCEPROC) gl3w__get_proc("glShaderSource");
	gl3wShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC) gl3w__get_proc("glShaderStorageBlockBinding");
	gl3wSignalVkFenceNV = (PFNGLSIGNALVKFENCENVPROC) gl3w__get_proc("glSignalVkFenceNV");
	gl3wSignalVkSemaphoreNV = (PFNGLSIGNALVKSEMAPHORENVPROC) gl3w__get_proc("glSignalVkSemaphoreNV");
	gl3wSpecializeShader = (PFNGLSPECIALIZESHADERPROC) gl3w__get_proc("glSpecializeShader");
	gl3wSpecializeShaderARB = (PFNGLSPECIALIZESHADERARBPROC) gl3w__get_proc("glSpecializeShaderARB");
	gl3wStateCaptureNV = (PFNGLSTATECAPTURENVPROC) gl3w__get_proc("glStateCaptureNV");
	gl3wStencilFillPathInstancedNV = (PFNGLSTENCILFILLPATHINSTANCEDNVPROC) gl3w__get_proc("glStencilFillPathInstancedNV");
	gl3wStencilFillPathNV = (PFNGLSTENCILFILLPATHNVPROC) gl3w__get_proc("glStencilFillPathNV");
	gl3wStencilFunc = (PFNGLSTENCILFUNCPROC) gl3w__get_proc("glStencilFunc");
	gl3wStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) gl3w__get_proc("glStencilFuncSeparate");
	gl3wStencilMask = (PFNGLSTENCILMASKPROC) gl3w__get_proc("glStencilMask");
	gl3wStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC) gl3w__get_proc("glStencilMaskSeparate");
	gl3wStencilOp = (PFNGLSTENCILOPPROC) gl3w__get_proc("glStencilOp");
	gl3wStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) gl3w__get_proc("glStencilOpSeparate");
	gl3wStencilStrokePathInstancedNV = (PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC) gl3w__get_proc("glStencilStrokePathInstancedNV");
	gl3wStencilStrokePathNV = (PFNGLSTENCILSTROKEPATHNVPROC) gl3w__get_proc("glStencilStrokePathNV");
	gl3wStencilThenCoverFillPathInstancedNV = (PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC) gl3w__get_proc("glStencilThenCoverFillPathInstancedNV");
	gl3wStencilThenCoverFillPathNV = (PFNGLSTENCILTHENCOVERFILLPATHNVPROC) gl3w__get_proc("glStencilThenCoverFillPathNV");
	gl3wStencilThenCoverStrokePathInstancedNV = (PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC) gl3w__get_proc("glStencilThenCoverStrokePathInstancedNV");
	gl3wStencilThenCoverStrokePathNV = (PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC) gl3w__get_proc("glStencilThenCoverStrokePathNV");
	gl3wSubpixelPrecisionBiasNV = (PFNGLSUBPIXELPRECISIONBIASNVPROC) gl3w__get_proc("glSubpixelPrecisionBiasNV");
	gl3wTexBuffer = (PFNGLTEXBUFFERPROC) gl3w__get_proc("glTexBuffer");
	gl3wTexBufferARB = (PFNGLTEXBUFFERARBPROC) gl3w__get_proc("glTexBufferARB");
	gl3wTexBufferRange = (PFNGLTEXBUFFERRANGEPROC) gl3w__get_proc("glTexBufferRange");
	gl3wTexCoordFormatNV = (PFNGLTEXCOORDFORMATNVPROC) gl3w__get_proc("glTexCoordFormatNV");
	gl3wTexImage1D = (PFNGLTEXIMAGE1DPROC) gl3w__get_proc("glTexImage1D");
	gl3wTexImage2D = (PFNGLTEXIMAGE2DPROC) gl3w__get_proc("glTexImage2D");
	gl3wTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC) gl3w__get_proc("glTexImage2DMultisample");
	gl3wTexImage3D = (PFNGLTEXIMAGE3DPROC) gl3w__get_proc("glTexImage3D");
	gl3wTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC) gl3w__get_proc("glTexImage3DMultisample");
	gl3wTexPageCommitmentARB = (PFNGLTEXPAGECOMMITMENTARBPROC) gl3w__get_proc("glTexPageCommitmentARB");
	gl3wTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC) gl3w__get_proc("glTexParameterIiv");
	gl3wTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC) gl3w__get_proc("glTexParameterIuiv");
	gl3wTexParameterf = (PFNGLTEXPARAMETERFPROC) gl3w__get_proc("glTexParameterf");
	gl3wTexParameterfv = (PFNGLTEXPARAMETERFVPROC) gl3w__get_proc("glTexParameterfv");
	gl3wTexParameteri = (PFNGLTEXPARAMETERIPROC) gl3w__get_proc("glTexParameteri");
	gl3wTexParameteriv = (PFNGLTEXPARAMETERIVPROC) gl3w__get_proc("glTexParameteriv");
	gl3wTexStorage1D = (PFNGLTEXSTORAGE1DPROC) gl3w__get_proc("glTexStorage1D");
	gl3wTexStorage2D = (PFNGLTEXSTORAGE2DPROC) gl3w__get_proc("glTexStorage2D");
	gl3wTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC) gl3w__get_proc("glTexStorage2DMultisample");
	gl3wTexStorage3D = (PFNGLTEXSTORAGE3DPROC) gl3w__get_proc("glTexStorage3D");
	gl3wTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC) gl3w__get_proc("glTexStorage3DMultisample");
	gl3wTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC) gl3w__get_proc("glTexSubImage1D");
	gl3wTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC) gl3w__get_proc("glTexSubImage2D");
	gl3wTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC) gl3w__get_proc("glTexSubImage3D");
	gl3wTextureBarrier = (PFNGLTEXTUREBARRIERPROC) gl3w__get_proc("glTextureBarrier");
	gl3wTextureBarrierNV = (PFNGLTEXTUREBARRIERNVPROC) gl3w__get_proc("glTextureBarrierNV");
	gl3wTextureBuffer = (PFNGLTEXTUREBUFFERPROC) gl3w__get_proc("glTextureBuffer");
	gl3wTextureBufferEXT = (PFNGLTEXTUREBUFFEREXTPROC) gl3w__get_proc("glTextureBufferEXT");
	gl3wTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC) gl3w__get_proc("glTextureBufferRange");
	gl3wTextureBufferRangeEXT = (PFNGLTEXTUREBUFFERRANGEEXTPROC) gl3w__get_proc("glTextureBufferRangeEXT");
	gl3wTextureImage1DEXT = (PFNGLTEXTUREIMAGE1DEXTPROC) gl3w__get_proc("glTextureImage1DEXT");
	gl3wTextureImage2DEXT = (PFNGLTEXTUREIMAGE2DEXTPROC) gl3w__get_proc("glTextureImage2DEXT");
	gl3wTextureImage3DEXT = (PFNGLTEXTUREIMAGE3DEXTPROC) gl3w__get_proc("glTextureImage3DEXT");
	gl3wTexturePageCommitmentEXT = (PFNGLTEXTUREPAGECOMMITMENTEXTPROC) gl3w__get_proc("glTexturePageCommitmentEXT");
	gl3wTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC) gl3w__get_proc("glTextureParameterIiv");
	gl3wTextureParameterIivEXT = (PFNGLTEXTUREPARAMETERIIVEXTPROC) gl3w__get_proc("glTextureParameterIivEXT");
	gl3wTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC) gl3w__get_proc("glTextureParameterIuiv");
	gl3wTextureParameterIuivEXT = (PFNGLTEXTUREPARAMETERIUIVEXTPROC) gl3w__get_proc("glTextureParameterIuivEXT");
	gl3wTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC) gl3w__get_proc("glTextureParameterf");
	gl3wTextureParameterfEXT = (PFNGLTEXTUREPARAMETERFEXTPROC) gl3w__get_proc("glTextureParameterfEXT");
	gl3wTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC) gl3w__get_proc("glTextureParameterfv");
	gl3wTextureParameterfvEXT = (PFNGLTEXTUREPARAMETERFVEXTPROC) gl3w__get_proc("glTextureParameterfvEXT");
	gl3wTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC) gl3w__get_proc("glTextureParameteri");
	gl3wTextureParameteriEXT = (PFNGLTEXTUREPARAMETERIEXTPROC) gl3w__get_proc("glTextureParameteriEXT");
	gl3wTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC) gl3w__get_proc("glTextureParameteriv");
	gl3wTextureParameterivEXT = (PFNGLTEXTUREPARAMETERIVEXTPROC) gl3w__get_proc("glTextureParameterivEXT");
	gl3wTextureRenderbufferEXT = (PFNGLTEXTURERENDERBUFFEREXTPROC) gl3w__get_proc("glTextureRenderbufferEXT");
	gl3wTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC) gl3w__get_proc("glTextureStorage1D");
	gl3wTextureStorage1DEXT = (PFNGLTEXTURESTORAGE1DEXTPROC) gl3w__get_proc("glTextureStorage1DEXT");
	gl3wTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC) gl3w__get_proc("glTextureStorage2D");
	gl3wTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXTPROC) gl3w__get_proc("glTextureStorage2DEXT");
	gl3wTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) gl3w__get_proc("glTextureStorage2DMultisample");
	gl3wTextureStorage2DMultisampleEXT = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC) gl3w__get_proc("glTextureStorage2DMultisampleEXT");
	gl3wTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC) gl3w__get_proc("glTextureStorage3D");
	gl3wTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXTPROC) gl3w__get_proc("glTextureStorage3DEXT");
	gl3wTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) gl3w__get_proc("glTextureStorage3DMultisample");
	gl3wTextureStorage3DMultisampleEXT = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC) gl3w__get_proc("glTextureStorage3DMultisampleEXT");
	gl3wTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC) gl3w__get_proc("glTextureSubImage1D");
	gl3wTextureSubImage1DEXT = (PFNGLTEXTURESUBIMAGE1DEXTPROC) gl3w__get_proc("glTextureSubImage1DEXT");
	gl3wTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC) gl3w__get_proc("glTextureSubImage2D");
	gl3wTextureSubImage2DEXT = (PFNGLTEXTURESUBIMAGE2DEXTPROC) gl3w__get_proc("glTextureSubImage2DEXT");
	gl3wTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC) gl3w__get_proc("glTextureSubImage3D");
	gl3wTextureSubImage3DEXT = (PFNGLTEXTURESUBIMAGE3DEXTPROC) gl3w__get_proc("glTextureSubImage3DEXT");
	gl3wTextureView = (PFNGLTEXTUREVIEWPROC) gl3w__get_proc("glTextureView");
	gl3wTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) gl3w__get_proc("glTransformFeedbackBufferBase");
	gl3wTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) gl3w__get_proc("glTransformFeedbackBufferRange");
	gl3wTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC) gl3w__get_proc("glTransformFeedbackVaryings");
	gl3wTransformPathNV = (PFNGLTRANSFORMPATHNVPROC) gl3w__get_proc("glTransformPathNV");
	gl3wUniform1d = (PFNGLUNIFORM1DPROC) gl3w__get_proc("glUniform1d");
	gl3wUniform1dv = (PFNGLUNIFORM1DVPROC) gl3w__get_proc("glUniform1dv");
	gl3wUniform1f = (PFNGLUNIFORM1FPROC) gl3w__get_proc("glUniform1f");
	gl3wUniform1fv = (PFNGLUNIFORM1FVPROC) gl3w__get_proc("glUniform1fv");
	gl3wUniform1i = (PFNGLUNIFORM1IPROC) gl3w__get_proc("glUniform1i");
	gl3wUniform1i64ARB = (PFNGLUNIFORM1I64ARBPROC) gl3w__get_proc("glUniform1i64ARB");
	gl3wUniform1i64NV = (PFNGLUNIFORM1I64NVPROC) gl3w__get_proc("glUniform1i64NV");
	gl3wUniform1i64vARB = (PFNGLUNIFORM1I64VARBPROC) gl3w__get_proc("glUniform1i64vARB");
	gl3wUniform1i64vNV = (PFNGLUNIFORM1I64VNVPROC) gl3w__get_proc("glUniform1i64vNV");
	gl3wUniform1iv = (PFNGLUNIFORM1IVPROC) gl3w__get_proc("glUniform1iv");
	gl3wUniform1ui = (PFNGLUNIFORM1UIPROC) gl3w__get_proc("glUniform1ui");
	gl3wUniform1ui64ARB = (PFNGLUNIFORM1UI64ARBPROC) gl3w__get_proc("glUniform1ui64ARB");
	gl3wUniform1ui64NV = (PFNGLUNIFORM1UI64NVPROC) gl3w__get_proc("glUniform1ui64NV");
	gl3wUniform1ui64vARB = (PFNGLUNIFORM1UI64VARBPROC) gl3w__get_proc("glUniform1ui64vARB");
	gl3wUniform1ui64vNV = (PFNGLUNIFORM1UI64VNVPROC) gl3w__get_proc("glUniform1ui64vNV");
	gl3wUniform1uiv = (PFNGLUNIFORM1UIVPROC) gl3w__get_proc("glUniform1uiv");
	gl3wUniform2d = (PFNGLUNIFORM2DPROC) gl3w__get_proc("glUniform2d");
	gl3wUniform2dv = (PFNGLUNIFORM2DVPROC) gl3w__get_proc("glUniform2dv");
	gl3wUniform2f = (PFNGLUNIFORM2FPROC) gl3w__get_proc("glUniform2f");
	gl3wUniform2fv = (PFNGLUNIFORM2FVPROC) gl3w__get_proc("glUniform2fv");
	gl3wUniform2i = (PFNGLUNIFORM2IPROC) gl3w__get_proc("glUniform2i");
	gl3wUniform2i64ARB = (PFNGLUNIFORM2I64ARBPROC) gl3w__get_proc("glUniform2i64ARB");
	gl3wUniform2i64NV = (PFNGLUNIFORM2I64NVPROC) gl3w__get_proc("glUniform2i64NV");
	gl3wUniform2i64vARB = (PFNGLUNIFORM2I64VARBPROC) gl3w__get_proc("glUniform2i64vARB");
	gl3wUniform2i64vNV = (PFNGLUNIFORM2I64VNVPROC) gl3w__get_proc("glUniform2i64vNV");
	gl3wUniform2iv = (PFNGLUNIFORM2IVPROC) gl3w__get_proc("glUniform2iv");
	gl3wUniform2ui = (PFNGLUNIFORM2UIPROC) gl3w__get_proc("glUniform2ui");
	gl3wUniform2ui64ARB = (PFNGLUNIFORM2UI64ARBPROC) gl3w__get_proc("glUniform2ui64ARB");
	gl3wUniform2ui64NV = (PFNGLUNIFORM2UI64NVPROC) gl3w__get_proc("glUniform2ui64NV");
	gl3wUniform2ui64vARB = (PFNGLUNIFORM2UI64VARBPROC) gl3w__get_proc("glUniform2ui64vARB");
	gl3wUniform2ui64vNV = (PFNGLUNIFORM2UI64VNVPROC) gl3w__get_proc("glUniform2ui64vNV");
	gl3wUniform2uiv = (PFNGLUNIFORM2UIVPROC) gl3w__get_proc("glUniform2uiv");
	gl3wUniform3d = (PFNGLUNIFORM3DPROC) gl3w__get_proc("glUniform3d");
	gl3wUniform3dv = (PFNGLUNIFORM3DVPROC) gl3w__get_proc("glUniform3dv");
	gl3wUniform3f = (PFNGLUNIFORM3FPROC) gl3w__get_proc("glUniform3f");
	gl3wUniform3fv = (PFNGLUNIFORM3FVPROC) gl3w__get_proc("glUniform3fv");
	gl3wUniform3i = (PFNGLUNIFORM3IPROC) gl3w__get_proc("glUniform3i");
	gl3wUniform3i64ARB = (PFNGLUNIFORM3I64ARBPROC) gl3w__get_proc("glUniform3i64ARB");
	gl3wUniform3i64NV = (PFNGLUNIFORM3I64NVPROC) gl3w__get_proc("glUniform3i64NV");
	gl3wUniform3i64vARB = (PFNGLUNIFORM3I64VARBPROC) gl3w__get_proc("glUniform3i64vARB");
	gl3wUniform3i64vNV = (PFNGLUNIFORM3I64VNVPROC) gl3w__get_proc("glUniform3i64vNV");
	gl3wUniform3iv = (PFNGLUNIFORM3IVPROC) gl3w__get_proc("glUniform3iv");
	gl3wUniform3ui = (PFNGLUNIFORM3UIPROC) gl3w__get_proc("glUniform3ui");
	gl3wUniform3ui64ARB = (PFNGLUNIFORM3UI64ARBPROC) gl3w__get_proc("glUniform3ui64ARB");
	gl3wUniform3ui64NV = (PFNGLUNIFORM3UI64NVPROC) gl3w__get_proc("glUniform3ui64NV");
	gl3wUniform3ui64vARB = (PFNGLUNIFORM3UI64VARBPROC) gl3w__get_proc("glUniform3ui64vARB");
	gl3wUniform3ui64vNV = (PFNGLUNIFORM3UI64VNVPROC) gl3w__get_proc("glUniform3ui64vNV");
	gl3wUniform3uiv = (PFNGLUNIFORM3UIVPROC) gl3w__get_proc("glUniform3uiv");
	gl3wUniform4d = (PFNGLUNIFORM4DPROC) gl3w__get_proc("glUniform4d");
	gl3wUniform4dv = (PFNGLUNIFORM4DVPROC) gl3w__get_proc("glUniform4dv");
	gl3wUniform4f = (PFNGLUNIFORM4FPROC) gl3w__get_proc("glUniform4f");
	gl3wUniform4fv = (PFNGLUNIFORM4FVPROC) gl3w__get_proc("glUniform4fv");
	gl3wUniform4i = (PFNGLUNIFORM4IPROC) gl3w__get_proc("glUniform4i");
	gl3wUniform4i64ARB = (PFNGLUNIFORM4I64ARBPROC) gl3w__get_proc("glUniform4i64ARB");
	gl3wUniform4i64NV = (PFNGLUNIFORM4I64NVPROC) gl3w__get_proc("glUniform4i64NV");
	gl3wUniform4i64vARB = (PFNGLUNIFORM4I64VARBPROC) gl3w__get_proc("glUniform4i64vARB");
	gl3wUniform4i64vNV = (PFNGLUNIFORM4I64VNVPROC) gl3w__get_proc("glUniform4i64vNV");
	gl3wUniform4iv = (PFNGLUNIFORM4IVPROC) gl3w__get_proc("glUniform4iv");
	gl3wUniform4ui = (PFNGLUNIFORM4UIPROC) gl3w__get_proc("glUniform4ui");
	gl3wUniform4ui64ARB = (PFNGLUNIFORM4UI64ARBPROC) gl3w__get_proc("glUniform4ui64ARB");
	gl3wUniform4ui64NV = (PFNGLUNIFORM4UI64NVPROC) gl3w__get_proc("glUniform4ui64NV");
	gl3wUniform4ui64vARB = (PFNGLUNIFORM4UI64VARBPROC) gl3w__get_proc("glUniform4ui64vARB");
	gl3wUniform4ui64vNV = (PFNGLUNIFORM4UI64VNVPROC) gl3w__get_proc("glUniform4ui64vNV");
	gl3wUniform4uiv = (PFNGLUNIFORM4UIVPROC) gl3w__get_proc("glUniform4uiv");
	gl3wUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC) gl3w__get_proc("glUniformBlockBinding");
	gl3wUniformHandleui64ARB = (PFNGLUNIFORMHANDLEUI64ARBPROC) gl3w__get_proc("glUniformHandleui64ARB");
	gl3wUniformHandleui64NV = (PFNGLUNIFORMHANDLEUI64NVPROC) gl3w__get_proc("glUniformHandleui64NV");
	gl3wUniformHandleui64vARB = (PFNGLUNIFORMHANDLEUI64VARBPROC) gl3w__get_proc("glUniformHandleui64vARB");
	gl3wUniformHandleui64vNV = (PFNGLUNIFORMHANDLEUI64VNVPROC) gl3w__get_proc("glUniformHandleui64vNV");
	gl3wUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC) gl3w__get_proc("glUniformMatrix2dv");
	gl3wUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) gl3w__get_proc("glUniformMatrix2fv");
	gl3wUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC) gl3w__get_proc("glUniformMatrix2x3dv");
	gl3wUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) gl3w__get_proc("glUniformMatrix2x3fv");
	gl3wUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC) gl3w__get_proc("glUniformMatrix2x4dv");
	gl3wUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) gl3w__get_proc("glUniformMatrix2x4fv");
	gl3wUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC) gl3w__get_proc("glUniformMatrix3dv");
	gl3wUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) gl3w__get_proc("glUniformMatrix3fv");
	gl3wUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC) gl3w__get_proc("glUniformMatrix3x2dv");
	gl3wUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) gl3w__get_proc("glUniformMatrix3x2fv");
	gl3wUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC) gl3w__get_proc("glUniformMatrix3x4dv");
	gl3wUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) gl3w__get_proc("glUniformMatrix3x4fv");
	gl3wUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC) gl3w__get_proc("glUniformMatrix4dv");
	gl3wUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) gl3w__get_proc("glUniformMatrix4fv");
	gl3wUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC) gl3w__get_proc("glUniformMatrix4x2dv");
	gl3wUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) gl3w__get_proc("glUniformMatrix4x2fv");
	gl3wUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC) gl3w__get_proc("glUniformMatrix4x3dv");
	gl3wUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) gl3w__get_proc("glUniformMatrix4x3fv");
	gl3wUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC) gl3w__get_proc("glUniformSubroutinesuiv");
	gl3wUniformui64NV = (PFNGLUNIFORMUI64NVPROC) gl3w__get_proc("glUniformui64NV");
	gl3wUniformui64vNV = (PFNGLUNIFORMUI64VNVPROC) gl3w__get_proc("glUniformui64vNV");
	gl3wUnmapBuffer = (PFNGLUNMAPBUFFERPROC) gl3w__get_proc("glUnmapBuffer");
	gl3wUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC) gl3w__get_proc("glUnmapNamedBuffer");
	gl3wUnmapNamedBufferEXT = (PFNGLUNMAPNAMEDBUFFEREXTPROC) gl3w__get_proc("glUnmapNamedBufferEXT");
	gl3wUseProgram = (PFNGLUSEPROGRAMPROC) gl3w__get_proc("glUseProgram");
	gl3wUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC) gl3w__get_proc("glUseProgramStages");
	gl3wUseShaderProgramEXT = (PFNGLUSESHADERPROGRAMEXTPROC) gl3w__get_proc("glUseShaderProgramEXT");
	gl3wValidateProgram = (PFNGLVALIDATEPROGRAMPROC) gl3w__get_proc("glValidateProgram");
	gl3wValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC) gl3w__get_proc("glValidateProgramPipeline");
	gl3wVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC) gl3w__get_proc("glVertexArrayAttribBinding");
	gl3wVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC) gl3w__get_proc("glVertexArrayAttribFormat");
	gl3wVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC) gl3w__get_proc("glVertexArrayAttribIFormat");
	gl3wVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC) gl3w__get_proc("glVertexArrayAttribLFormat");
	gl3wVertexArrayBindVertexBufferEXT = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC) gl3w__get_proc("glVertexArrayBindVertexBufferEXT");
	gl3wVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC) gl3w__get_proc("glVertexArrayBindingDivisor");
	gl3wVertexArrayColorOffsetEXT = (PFNGLVERTEXARRAYCOLOROFFSETEXTPROC) gl3w__get_proc("glVertexArrayColorOffsetEXT");
	gl3wVertexArrayEdgeFlagOffsetEXT = (PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC) gl3w__get_proc("glVertexArrayEdgeFlagOffsetEXT");
	gl3wVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC) gl3w__get_proc("glVertexArrayElementBuffer");
	gl3wVertexArrayFogCoordOffsetEXT = (PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC) gl3w__get_proc("glVertexArrayFogCoordOffsetEXT");
	gl3wVertexArrayIndexOffsetEXT = (PFNGLVERTEXARRAYINDEXOFFSETEXTPROC) gl3w__get_proc("glVertexArrayIndexOffsetEXT");
	gl3wVertexArrayMultiTexCoordOffsetEXT = (PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC) gl3w__get_proc("glVertexArrayMultiTexCoordOffsetEXT");
	gl3wVertexArrayNormalOffsetEXT = (PFNGLVERTEXARRAYNORMALOFFSETEXTPROC) gl3w__get_proc("glVertexArrayNormalOffsetEXT");
	gl3wVertexArraySecondaryColorOffsetEXT = (PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC) gl3w__get_proc("glVertexArraySecondaryColorOffsetEXT");
	gl3wVertexArrayTexCoordOffsetEXT = (PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC) gl3w__get_proc("glVertexArrayTexCoordOffsetEXT");
	gl3wVertexArrayVertexAttribBindingEXT = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC) gl3w__get_proc("glVertexArrayVertexAttribBindingEXT");
	gl3wVertexArrayVertexAttribDivisorEXT = (PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC) gl3w__get_proc("glVertexArrayVertexAttribDivisorEXT");
	gl3wVertexArrayVertexAttribFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC) gl3w__get_proc("glVertexArrayVertexAttribFormatEXT");
	gl3wVertexArrayVertexAttribIFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC) gl3w__get_proc("glVertexArrayVertexAttribIFormatEXT");
	gl3wVertexArrayVertexAttribIOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC) gl3w__get_proc("glVertexArrayVertexAttribIOffsetEXT");
	gl3wVertexArrayVertexAttribLFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC) gl3w__get_proc("glVertexArrayVertexAttribLFormatEXT");
	gl3wVertexArrayVertexAttribLOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC) gl3w__get_proc("glVertexArrayVertexAttribLOffsetEXT");
	gl3wVertexArrayVertexAttribOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC) gl3w__get_proc("glVertexArrayVertexAttribOffsetEXT");
	gl3wVertexArrayVertexBindingDivisorEXT = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC) gl3w__get_proc("glVertexArrayVertexBindingDivisorEXT");
	gl3wVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC) gl3w__get_proc("glVertexArrayVertexBuffer");
	gl3wVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC) gl3w__get_proc("glVertexArrayVertexBuffers");
	gl3wVertexArrayVertexOffsetEXT = (PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC) gl3w__get_proc("glVertexArrayVertexOffsetEXT");
	gl3wVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC) gl3w__get_proc("glVertexAttrib1d");
	gl3wVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC) gl3w__get_proc("glVertexAttrib1dv");
	gl3wVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC) gl3w__get_proc("glVertexAttrib1f");
	gl3wVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC) gl3w__get_proc("glVertexAttrib1fv");
	gl3wVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC) gl3w__get_proc("glVertexAttrib1s");
	gl3wVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC) gl3w__get_proc("glVertexAttrib1sv");
	gl3wVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC) gl3w__get_proc("glVertexAttrib2d");
	gl3wVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC) gl3w__get_proc("glVertexAttrib2dv");
	gl3wVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC) gl3w__get_proc("glVertexAttrib2f");
	gl3wVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC) gl3w__get_proc("glVertexAttrib2fv");
	gl3wVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC) gl3w__get_proc("glVertexAttrib2s");
	gl3wVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC) gl3w__get_proc("glVertexAttrib2sv");
	gl3wVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC) gl3w__get_proc("glVertexAttrib3d");
	gl3wVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC) gl3w__get_proc("glVertexAttrib3dv");
	gl3wVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC) gl3w__get_proc("glVertexAttrib3f");
	gl3wVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC) gl3w__get_proc("glVertexAttrib3fv");
	gl3wVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC) gl3w__get_proc("glVertexAttrib3s");
	gl3wVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC) gl3w__get_proc("glVertexAttrib3sv");
	gl3wVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC) gl3w__get_proc("glVertexAttrib4Nbv");
	gl3wVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC) gl3w__get_proc("glVertexAttrib4Niv");
	gl3wVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC) gl3w__get_proc("glVertexAttrib4Nsv");
	gl3wVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC) gl3w__get_proc("glVertexAttrib4Nub");
	gl3wVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC) gl3w__get_proc("glVertexAttrib4Nubv");
	gl3wVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC) gl3w__get_proc("glVertexAttrib4Nuiv");
	gl3wVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC) gl3w__get_proc("glVertexAttrib4Nusv");
	gl3wVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC) gl3w__get_proc("glVertexAttrib4bv");
	gl3wVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC) gl3w__get_proc("glVertexAttrib4d");
	gl3wVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC) gl3w__get_proc("glVertexAttrib4dv");
	gl3wVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC) gl3w__get_proc("glVertexAttrib4f");
	gl3wVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC) gl3w__get_proc("glVertexAttrib4fv");
	gl3wVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC) gl3w__get_proc("glVertexAttrib4iv");
	gl3wVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC) gl3w__get_proc("glVertexAttrib4s");
	gl3wVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC) gl3w__get_proc("glVertexAttrib4sv");
	gl3wVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC) gl3w__get_proc("glVertexAttrib4ubv");
	gl3wVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC) gl3w__get_proc("glVertexAttrib4uiv");
	gl3wVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC) gl3w__get_proc("glVertexAttrib4usv");
	gl3wVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC) gl3w__get_proc("glVertexAttribBinding");
	gl3wVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC) gl3w__get_proc("glVertexAttribDivisor");
	gl3wVertexAttribDivisorARB = (PFNGLVERTEXATTRIBDIVISORARBPROC) gl3w__get_proc("glVertexAttribDivisorARB");
	gl3wVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC) gl3w__get_proc("glVertexAttribFormat");
	gl3wVertexAttribFormatNV = (PFNGLVERTEXATTRIBFORMATNVPROC) gl3w__get_proc("glVertexAttribFormatNV");
	gl3wVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC) gl3w__get_proc("glVertexAttribI1i");
	gl3wVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC) gl3w__get_proc("glVertexAttribI1iv");
	gl3wVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC) gl3w__get_proc("glVertexAttribI1ui");
	gl3wVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC) gl3w__get_proc("glVertexAttribI1uiv");
	gl3wVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC) gl3w__get_proc("glVertexAttribI2i");
	gl3wVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC) gl3w__get_proc("glVertexAttribI2iv");
	gl3wVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC) gl3w__get_proc("glVertexAttribI2ui");
	gl3wVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC) gl3w__get_proc("glVertexAttribI2uiv");
	gl3wVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC) gl3w__get_proc("glVertexAttribI3i");
	gl3wVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC) gl3w__get_proc("glVertexAttribI3iv");
	gl3wVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC) gl3w__get_proc("glVertexAttribI3ui");
	gl3wVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC) gl3w__get_proc("glVertexAttribI3uiv");
	gl3wVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC) gl3w__get_proc("glVertexAttribI4bv");
	gl3wVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC) gl3w__get_proc("glVertexAttribI4i");
	gl3wVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC) gl3w__get_proc("glVertexAttribI4iv");
	gl3wVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC) gl3w__get_proc("glVertexAttribI4sv");
	gl3wVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC) gl3w__get_proc("glVertexAttribI4ubv");
	gl3wVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC) gl3w__get_proc("glVertexAttribI4ui");
	gl3wVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC) gl3w__get_proc("glVertexAttribI4uiv");
	gl3wVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC) gl3w__get_proc("glVertexAttribI4usv");
	gl3wVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC) gl3w__get_proc("glVertexAttribIFormat");
	gl3wVertexAttribIFormatNV = (PFNGLVERTEXATTRIBIFORMATNVPROC) gl3w__get_proc("glVertexAttribIFormatNV");
	gl3wVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC) gl3w__get_proc("glVertexAttribIPointer");
	gl3wVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC) gl3w__get_proc("glVertexAttribL1d");
	gl3wVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC) gl3w__get_proc("glVertexAttribL1dv");
	gl3wVertexAttribL1i64NV = (PFNGLVERTEXATTRIBL1I64NVPROC) gl3w__get_proc("glVertexAttribL1i64NV");
	gl3wVertexAttribL1i64vNV = (PFNGLVERTEXATTRIBL1I64VNVPROC) gl3w__get_proc("glVertexAttribL1i64vNV");
	gl3wVertexAttribL1ui64ARB = (PFNGLVERTEXATTRIBL1UI64ARBPROC) gl3w__get_proc("glVertexAttribL1ui64ARB");
	gl3wVertexAttribL1ui64NV = (PFNGLVERTEXATTRIBL1UI64NVPROC) gl3w__get_proc("glVertexAttribL1ui64NV");
	gl3wVertexAttribL1ui64vARB = (PFNGLVERTEXATTRIBL1UI64VARBPROC) gl3w__get_proc("glVertexAttribL1ui64vARB");
	gl3wVertexAttribL1ui64vNV = (PFNGLVERTEXATTRIBL1UI64VNVPROC) gl3w__get_proc("glVertexAttribL1ui64vNV");
	gl3wVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC) gl3w__get_proc("glVertexAttribL2d");
	gl3wVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC) gl3w__get_proc("glVertexAttribL2dv");
	gl3wVertexAttribL2i64NV = (PFNGLVERTEXATTRIBL2I64NVPROC) gl3w__get_proc("glVertexAttribL2i64NV");
	gl3wVertexAttribL2i64vNV = (PFNGLVERTEXATTRIBL2I64VNVPROC) gl3w__get_proc("glVertexAttribL2i64vNV");
	gl3wVertexAttribL2ui64NV = (PFNGLVERTEXATTRIBL2UI64NVPROC) gl3w__get_proc("glVertexAttribL2ui64NV");
	gl3wVertexAttribL2ui64vNV = (PFNGLVERTEXATTRIBL2UI64VNVPROC) gl3w__get_proc("glVertexAttribL2ui64vNV");
	gl3wVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC) gl3w__get_proc("glVertexAttribL3d");
	gl3wVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC) gl3w__get_proc("glVertexAttribL3dv");
	gl3wVertexAttribL3i64NV = (PFNGLVERTEXATTRIBL3I64NVPROC) gl3w__get_proc("glVertexAttribL3i64NV");
	gl3wVertexAttribL3i64vNV = (PFNGLVERTEXATTRIBL3I64VNVPROC) gl3w__get_proc("glVertexAttribL3i64vNV");
	gl3wVertexAttribL3ui64NV = (PFNGLVERTEXATTRIBL3UI64NVPROC) gl3w__get_proc("glVertexAttribL3ui64NV");
	gl3wVertexAttribL3ui64vNV = (PFNGLVERTEXATTRIBL3UI64VNVPROC) gl3w__get_proc("glVertexAttribL3ui64vNV");
	gl3wVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC) gl3w__get_proc("glVertexAttribL4d");
	gl3wVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC) gl3w__get_proc("glVertexAttribL4dv");
	gl3wVertexAttribL4i64NV = (PFNGLVERTEXATTRIBL4I64NVPROC) gl3w__get_proc("glVertexAttribL4i64NV");
	gl3wVertexAttribL4i64vNV = (PFNGLVERTEXATTRIBL4I64VNVPROC) gl3w__get_proc("glVertexAttribL4i64vNV");
	gl3wVertexAttribL4ui64NV = (PFNGLVERTEXATTRIBL4UI64NVPROC) gl3w__get_proc("glVertexAttribL4ui64NV");
	gl3wVertexAttribL4ui64vNV = (PFNGLVERTEXATTRIBL4UI64VNVPROC) gl3w__get_proc("glVertexAttribL4ui64vNV");
	gl3wVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC) gl3w__get_proc("glVertexAttribLFormat");
	gl3wVertexAttribLFormatNV = (PFNGLVERTEXATTRIBLFORMATNVPROC) gl3w__get_proc("glVertexAttribLFormatNV");
	gl3wVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC) gl3w__get_proc("glVertexAttribLPointer");
	gl3wVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC) gl3w__get_proc("glVertexAttribP1ui");
	gl3wVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC) gl3w__get_proc("glVertexAttribP1uiv");
	gl3wVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC) gl3w__get_proc("glVertexAttribP2ui");
	gl3wVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC) gl3w__get_proc("glVertexAttribP2uiv");
	gl3wVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC) gl3w__get_proc("glVertexAttribP3ui");
	gl3wVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC) gl3w__get_proc("glVertexAttribP3uiv");
	gl3wVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC) gl3w__get_proc("glVertexAttribP4ui");
	gl3wVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC) gl3w__get_proc("glVertexAttribP4uiv");
	gl3wVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) gl3w__get_proc("glVertexAttribPointer");
	gl3wVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC) gl3w__get_proc("glVertexBindingDivisor");
	gl3wVertexFormatNV = (PFNGLVERTEXFORMATNVPROC) gl3w__get_proc("glVertexFormatNV");
	gl3wViewport = (PFNGLVIEWPORTPROC) gl3w__get_proc("glViewport");
	gl3wViewportArrayv = (PFNGLVIEWPORTARRAYVPROC) gl3w__get_proc("glViewportArrayv");
	gl3wViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC) gl3w__get_proc("glViewportIndexedf");
	gl3wViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC) gl3w__get_proc("glViewportIndexedfv");
	gl3wViewportPositionWScaleNV = (PFNGLVIEWPORTPOSITIONWSCALENVPROC) gl3w__get_proc("glViewportPositionWScaleNV");
	gl3wViewportSwizzleNV = (PFNGLVIEWPORTSWIZZLENVPROC) gl3w__get_proc("glViewportSwizzleNV");
	gl3wWaitSync = (PFNGLWAITSYNCPROC) gl3w__get_proc("glWaitSync");
	gl3wWaitVkSemaphoreNV = (PFNGLWAITVKSEMAPHORENVPROC) gl3w__get_proc("glWaitVkSemaphoreNV");
	gl3wWeightPathsNV = (PFNGLWEIGHTPATHSNVPROC) gl3w__get_proc("glWeightPathsNV");
	gl3wWindowRectanglesEXT = (PFNGLWINDOWRECTANGLESEXTPROC) gl3w__get_proc("glWindowRectanglesEXT");
}


#endif /* GL3W_IMPLEMENTATION */
