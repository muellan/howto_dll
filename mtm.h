/******************************************************************************
 *
 *  MTM Library API
 *  
 * 
 ******************************************************************************/

#ifndef MTM_H_
#define MTM_H_


/*****************************************************************************
 * OS SPECIFIC DEFINITIONS
 *****************************************************************************/
#ifdef _WIN32

    /* MTM_EXPORT should *only* be defined when building the shared library */
    #ifdef MTM_EXPORT
        #define MTM_API __declspec(dllexport)
    #else
        #define MTM_API __declspec(dllimport)
    #endif

    /* defines calling convention */
    #ifdef MTM_CDECL
        #define MTM_CALL __cdecl
    #else
        #define MTM_CALL __stdcall
    #endif

#else /* _WIN32 not defined. */

    /* Define with no value on non-Windows OSes. */
    #define MTM_API
    #define MTM_CALL

#endif



/*****************************************************************************
 * EXPORTED TYPES AND FUNCTIONS
 *****************************************************************************/
/* Make sure functions are exported with C linkage under C++ compilers. */
#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief  rigid transformation
 */
struct transformation_t
{
    //rotation matrix (row major)
    double rot[3][3];
    //translation vector (x,y,z)
    double tra[3];
};


/**
 * @brief  description
 * @param  inarray1  ...
 * @param  size1     size of 1st array
 * @param  inarray2  ...
 * @param  size2     size of 2nd array
 * @return nothing
 */
MTM_API void MTM_CALL do_great_things(transformation_t* inarray1, int size1,
                                      transformation_t* inarray2, int size2);



#ifdef __cplusplus
}
#endif


#endif /* MTM_H */
