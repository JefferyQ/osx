/* @(#) $Header: /cvs/Darwin/src/live/tcpdump/tcpdump/sctpHeader.h,v 1.1.1.1 2002/05/29 00:05:46 landonf Exp $ (LBL) */

/* SCTP reference Implementation Copyright (C) 1999 Cisco And Motorola
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 4. Neither the name of Cisco nor of Motorola may be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the SCTP reference Implementation
 *
 * 
 * Please send any bug reports or fixes you make to one of the following email
 * addresses:
 * 
 * rstewar1@email.mot.com
 * kmorneau@cisco.com
 * qxie1@email.mot.com
 * 
 * Any bugs reported given to us we will try to fix... any fixes shared will
 * be incorperated into the next SCTP release.
 */


#ifndef __sctpHeader_h__
#define __sctpHeader_h__

#include <sctpConstants.h>

#ifdef	__cplusplus
extern "C" {
#endif

/* the sctp common header */

#ifdef TRU64
 #define _64BITS 1
#endif 

struct sctpHeader{
  u_short source;
  u_short destination;
  u_int verificationTag;
  u_int adler32;
};

/* various descriptor parsers */

struct sctpChunkDesc{
  u_char chunkID;
  u_char chunkFlg;
  u_short chunkLength;
};

struct sctpParamDesc{
  u_short paramType;
  u_short paramLength;
};


struct sctpRelChunkDesc{
  struct sctpChunkDesc chk;
  u_int serialNumber;
};

struct sctpVendorSpecificParam {
  struct sctpParamDesc p;  /* type must be 0xfffe */
  u_int vendorId;	   /* vendor ID from RFC 1700 */
  u_short vendorSpecificType;
  u_short vendorSpecificLen;
};


/* Structures for the control parts */



/* Sctp association init request/ack */

/* this is used for init ack, too */
struct sctpInitiation{
  u_int initTag;		/* tag of mine */
  u_int rcvWindowCredit;	/* rwnd */
  u_short NumPreopenStreams;	/* OS */
  u_short MaxInboundStreams;     /* MIS */
  u_int initialTSN;
  /* optional param's follow in sctpParamDesc form */
};

struct sctpV4IpAddress{
  struct sctpParamDesc p;	/* type is set to SCTP_IPV4_PARAM_TYPE, len=10 */
  u_int  ipAddress;
};


struct sctpV6IpAddress{
  struct sctpParamDesc p;	/* type is set to SCTP_IPV6_PARAM_TYPE, len=22 */
  u_char  ipAddress[16];
};

struct sctpDNSName{
  struct sctpParamDesc param;
  u_char name[1];
};


struct sctpCookiePreserve{
  struct sctpParamDesc p;	/* type is set to SCTP_COOKIE_PRESERVE, len=8 */
  u_int extraTime;
};


struct sctpTimeStamp{
  u_int ts_sec;
  u_int ts_usec;
};

/* wire structure of my cookie */
struct cookieMessage{
  u_int TieTag_curTag;			/* copied from assoc if present */
  u_int TieTag_hisTag; 		/* copied from assoc if present */
  int cookieLife;			/* life I will award this cookie */
  struct sctpTimeStamp timeEnteringState; /* the time I built cookie */
  struct sctpInitiation initAckISent;	/* the INIT-ACK that I sent to my peer */
  u_int addressWhereISent[4];		/* I make this 4 ints so I get 128bits for future */
  int addrtype;				/* address type */
  u_short locScope;			/* V6 local scope flag */
  u_short siteScope;			/* V6 site scope flag */
  /* at the end is tacked on the INIT chunk sent in
   * its entirety and of course our 
   * signature.
   */
};


/* this guy is for use when
 * I have a initiate message gloming the
 * things together.

 */
struct sctpUnifiedInit{
  struct sctpChunkDesc uh;
  struct sctpInitiation initm;
};

struct sctpSendableInit{
  struct sctpHeader mh;
  struct sctpUnifiedInit msg;
};


/* Selective Acknowledgement 
 * has the following structure with
 * a optional ammount of trailing int's
 * on the last part (based on the numberOfDesc 
 * field).
 */

struct sctpSelectiveAck{
  u_int highestConseqTSN;
  u_int updatedRwnd;
  u_short numberOfdesc;
  u_short numDupTsns;
};

struct sctpSelectiveFrag{
  u_short fragmentStart;
  u_short fragmentEnd;
};


struct sctpUnifiedSack{
  struct sctpChunkDesc uh;
  struct sctpSelectiveAck sack;
};

/* for both RTT request/response the
 * following is sent 
 */

struct sctpHBrequest {
  u_int time_value_1;
  u_int time_value_2;
};

/* here is what I read and respond with to. */
struct sctpHBunified{
  struct sctpChunkDesc hdr;
  struct sctpParamDesc hb;
};


/* here is what I send */
struct sctpHBsender{
  struct sctpChunkDesc hdr;
  struct sctpParamDesc hb;
  struct sctpHBrequest rtt;
  char addrFmt[SCTP_ADDRMAX];
  unsigned short userreq;
};
  


/* for the abort and shutdown ACK 
 * we must carry the init tag in the common header. Just the
 * common header is all that is needed with a chunk descriptor.
 */
struct sctpUnifiedAbort{
  struct sctpChunkDesc uh;
};

struct sctpUnifiedAbortLight{
  struct sctpHeader mh;
  struct sctpChunkDesc uh;
};

struct sctpUnifiedAbortHeavy{
  struct sctpHeader mh;
  struct sctpChunkDesc uh;
  unsigned short causeCode;
  unsigned short causeLen;
};

/* For the graceful shutdown we must carry
 * the tag (in common header)  and the highest consequitive acking value
 */
struct sctpShutdown {
  u_int TSN_Seen;
};

struct sctpUnifiedShutdown{
  struct sctpChunkDesc uh;
  struct sctpShutdown shut;
};

/* in the unified message we add the trailing
 * stream id since it is the only message
 * that is defined as a operation error.
 */
struct sctpOpErrorCause{
  u_short cause;
  u_short causeLen;
};

struct sctpUnifiedOpError{
  struct sctpChunkDesc uh;
  struct sctpOpErrorCause c;
};

struct sctpUnifiedStreamError{
  struct sctpHeader mh;
  struct sctpChunkDesc uh;
  struct sctpOpErrorCause c;
  u_short strmNum;
  u_short reserved;
};

struct staleCookieMsg{
  struct sctpHeader mh;
  struct sctpChunkDesc uh;
  struct sctpOpErrorCause c;
  u_int moretime;
};

/* the following is used in all sends
 * where nothing is needed except the
 * chunk/type i.e. shutdownAck Abort */

struct sctpUnifiedSingleMsg{
  struct sctpHeader mh;
  struct sctpChunkDesc uh;
};

struct sctpDataPart{
  u_int TSN;
  u_short streamId;
  u_short sequence;
  u_int payloadtype;
};

struct sctpUnifiedDatagram{
  struct sctpChunkDesc uh;
  struct sctpDataPart dp;
};

struct sctpECN_echo{
  struct sctpChunkDesc uh;
  u_int Lowest_TSN;
};    


struct sctpCWR{
  struct sctpChunkDesc uh;
  u_int TSN_reduced_at;
};    

#ifdef	__cplusplus
}
#endif

#endif
