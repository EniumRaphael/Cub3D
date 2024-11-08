/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:10:11 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/08 14:24:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H

/* ************************************************************************** */
/*                                                                            */
/* Module: ft_string														  */
/*																			  */
/* Prefix:																	  */
/*																			  */
/* Description:																  */
/*		- This file is part of the ft_string module. Was separated for		  */
/*		clarity.															  */
/*																			  */
/* ************************************************************************** */

# define EPERM 1
// EPERM 'Operation not permitted'

# define ENOENT 2
// ENOENT 'No such file or directory'

# define ESRCH 3
// ESRCH 'No such process'

# define EINTR 4
// EINTR 'Interrupted system call'

# define EIO 5
// EIO 'I/O error'

# define ENXIO 6
// ENXIO 'No such device or address'

# define E2BIG 7
// E2BIG 'Argument list too long'

# define ENOEXEC 8
// ENOEXEC 'Exec format error'

# define EBADF 9
// EBADF 'Bad file number'

# define ECHILD 10
// ECHILD 'No child processes'

# define EAGAIN 11
// EAGAIN 'Try again'

# define ENOMEM 12
// ENOMEM 'Out of memory'

# define EACCES 13
// EACCES 'Permission denied'

# define EFAULT 14
// EFAULT 'Bad address'

# define ENOTBLK 15
// ENOTBLK 'Block device required'

# define EBUSY 16
// EBUSY 'Device or resource busy'

# define EEXIST 17
// EEXIST 'File exists'

# define EXDEV 18
// EXDEV 'Cross-device link'

# define ENODEV 19
// ENODEV 'No such device'

# define ENOTDIR 20
// ENOTDIR 'Not a directory'

# define EISDIR 21
// EISDIR 'Is a directory'

# define EINVAL 22
// EINVAL 'Invalid argument'

# define ENFILE 23
// ENFILE 'File table overflow'

# define EMFILE 24
// EMFILE 'Too many open files'

# define ENOTTY 25
// ENOTTY 'Not a typewriter'

# define ETXTBSY 26
// ETXTBSY 'Text file busy'

# define EFBIG 27
// EFBIG 'File too large'

# define ENOSPC 28
// ENOSPC 'No space left on device'

# define ESPIPE 29
// ESPIPE 'Illegal seek'

# define EROFS 30
// EROFS 'Read-only file system'

# define EMLINK 31
// EMLINK 'Too many links'

# define EPIPE 32
// EPIPE 'Broken pipe'

# define EDOM 33
// EDOM 'Math argument out of domain of func'

# define ERANGE 34
// ERANGE 'Math result not representable'

# define EDEADLK 35
// EDEADLK 'Resource deadlock would occur'

# define ENAMETOOLONG 36
// ENAMETOOLONG 'File name too long'

# define ENOLCK 37
// ENOLCK 'No record locks available'

# define ENOSYS 38
// ENOSYS 'Function not implemented'

# define ENOTEMPTY 39
// ENOTEMPTY 'Directory not empty'

# define ELOOP 40
// ELOOP 'Too many symbolic links encountered'

# define ENOMSG 42
// ENOMSG 'No message of desired type'

# define EIDRM 43
// EIDRM 'Identifier removed'

# define ECHRNG 44
// ECHRNG 'Channel number out of range'

# define EL2NSYNC 45
// EL2NSYNC 'Level 2 not synchronized'

# define EL3HLT 46
// EL3HLT 'Level 3 halted'

# define EL3RST 47
// EL3RST 'Level 3 reset'

# define ELNRNG 48
// ELNRNG 'Link number out of range'

# define EUNATCH 49
// EUNATCH 'Protocol driver not attached'

# define ENOCSI 50
// ENOCSI 'No CSI structure available'

# define EL2HLT 51
// EL2HLT 'Level 2 halted'

# define EBADE 52
// EBADE 'Invalid exchange'

# define EBADR 53
// EBADR 'Invalid request descriptor'

# define EXFULL 54
// EXFULL 'Exchange full'

# define ENOANO 55
// ENOANO 'No anode'

# define EBADRQC 56
// EBADRQC 'Invalid request code'

# define EBADSLT 57
// EBADSLT 'Invalid slot'

# define EBFONT 59
// EBFONT 'Bad font file format'

# define ENOSTR 60
// ENOSTR 'Device not a stream'

# define ENODATA 61
// ENODATA 'No data available'

# define ETIME 62
// ETIME 'Timer expired'

# define ENOSR 63
// ENOSR 'Out of streams resources'

# define ENONET 64
// ENONET 'Machine is not on the network'

# define ENOPKG 65
// ENOPKG 'Package not installed'

# define EREMOTE 66
// EREMOTE 'Object is remote'

# define ENOLINK 67
// ENOLINK 'Link has been severed'

# define EADV 68
// EADV 'Advertise error'

# define ESRMNT 69
// ESRMNT 'Srmount error'

# define ECOMM 70
// ECOMM 'Communication error on send'

# define EPROTO 71
// EPROTO 'Protocol error'

# define EMULTIHOP 72
// EMULTIHOP 'Multihop attempted'

# define EDOTDOT 73
// EDOTDOT 'RFS specific error'

# define EBADMSG 74
// EBADMSG 'Not a data message'

# define EOVERFLOW 75
// EOVERFLOW 'Value too large for defined data type'

# define ENOTUNIQ 76
// ENOTUNIQ 'Name not unique on network'

# define EBADFD 77
// EBADFD 'File descriptor in bad state'

# define EREMCHG 78
// EREMCHG 'Remote address changed'

# define ELIBACC 79
// ELIBACC 'Can not access a needed shared library'

# define ELIBBAD 80
// ELIBBAD 'Accessing a corrupted shared library'

# define ELIBSCN 81
// ELIBSCN '.lib section in a.out corrupted'

# define ELIBMAX 82
// ELIBMAX 'Attempting to link in too many shared libraries'

# define ELIBEXEC 83
// ELIBEXEC 'Cannot exec a shared library directly'

# define EILSEQ 84
// EILSEQ 'Illegal byte sequence'

# define ERESTART 85
// ERESTART 'Interrupted system call should be restarted'

# define ESTRPIPE 86
// ESTRPIPE 'Streams pipe error'

# define EUSERS 87
// EUSERS 'Too many users'

# define ENOTSOCK 88
// ENOTSOCK 'Socket operation on non-socket'

# define EDESTADDRREQ 89
// EDESTADDRREQ 'Destination address required'

# define EMSGSIZE 90
// EMSGSIZE 'Message too long'

# define EPROTOTYPE 91
// EPROTOTYPE 'Protocol wrong type for socket'

# define ENOPROTOOPT 92
// ENOPROTOOPT 'Protocol not available'

# define EPROTONOSUPPORT 93
// EPROTONOSUPPORT 'Protocol not supported'

# define ESOCKTNOSUPPORT 94
// ESOCKTNOSUPPORT 'Socket type not supported'

# define EOPNOTSUPP 95
// EOPNOTSUPP 'Operation not supported on transport endpoint'

# define EPFNOSUPPORT 96
// EPFNOSUPPORT 'Protocol family not supported'

# define EAFNOSUPPORT 97
// EAFNOSUPPORT 'Address family not supported by protocol'

# define EADDRINUSE 98
// EADDRINUSE 'Address already in use'

# define EADDRNOTAVAIL 99
// EADDRNOTAVAIL 'Cannot assign requested address'

# define ENETDOWN 100
// ENETDOWN 'Network is down'

# define ENETUNREACH 101
// ENETUNREACH 'Network is unreachable'

# define ENETRESET 102
// ENETRESET 'Network dropped connection because of reset'

# define ECONNABORTED 103
// ECONNABORTED 'Software caused connection abort'

# define ECONNRESET 104
// ECONNRESET 'Connection reset by peer'

# define ENOBUFS 105
// ENOBUFS 'No buffer space available'

# define EISCONN 106
// EISCONN 'Transport endpoint is already connected'

# define ENOTCONN 107
// ENOTCONN 'Transport endpoint is not connected'

# define ESHUTDOWN 108
// ESHUTDOWN 'Cannot send after transport endpoint shutdown'

# define ETOOMANYREFS 109
// ETOOMANYREFS 'Too many references: cannot splice'

# define ETIMEDOUT 110
// ETIMEDOUT 'Connection timed out'

# define ECONNREFUSED 111
// ECONNREFUSED 'Connection refused'

# define EHOSTDOWN 112
// EHOSTDOWN 'Host is down'

# define EHOSTUNREACH 113
// EHOSTUNREACH 'No route to host'

# define EALREADY 114
// EALREADY 'Operation already in progress'

# define EINPROGRESS 115
// EINPROGRESS 'Operation now in progress'

# define ESTALE 116
// ESTALE 'Stale NFS file handle'

# define EUCLEAN 117
// EUCLEAN 'Structure needs cleaning'

# define ENOTNAM 118
// ENOTNAM 'Not a XENIX named type file'

# define ENAVAIL 119
// ENAVAIL 'No XENIX semaphores available'

# define EISNAM 120
// EISNAM 'Is a named type file'

# define EREMOTEIO 121
// EREMOTEIO 'Remote I/O error'

# define EDQUOT 122
// EDQUOT 'Quota exceeded'

# define ENOMEDIUM 123
// ENOMEDIUM 'No medium found'

# define EMEDIUMTYPE 124
// EMEDIUMTYPE 'Wrong medium type'

# define ECANCELED 125
// ECANCELED 'Operation Canceled'

# define ENOKEY 126
// ENOKEY 'Required key not available'

# define EKEYEXPIRED 127
// EKEYEXPIRED 'Key has expired'

# define EKEYREVOKED 128
// EKEYREVOKED 'Key has been revoked'

# define EKEYREJECTED 129
// EKEYREJECTED 'Key was rejected by service'

# define EOWNERDEAD 130
// EOWNERDEAD 'Owner died'

# define ENOTRECOVERABLE 131
// ENOTRECOVERABLE 'State not recoverable'

#endif /* FT_ERRNO_H */
