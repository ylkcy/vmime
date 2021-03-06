//
// VMime library (http://www.vmime.org)
// Copyright (C) 2002 Vincent Richard <vincent@vmime.org>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Linking this library statically or dynamically with other modules is making
// a combined work based on this library.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//

#ifndef VMIME_SECURITY_DIGEST_MD5_MD5MESSAGEDIGEST_HPP_INCLUDED
#define VMIME_SECURITY_DIGEST_MD5_MD5MESSAGEDIGEST_HPP_INCLUDED


#include "vmime/security/digest/messageDigest.hpp"


namespace vmime {
namespace security {
namespace digest {
namespace md5 {


class md5MessageDigest : public messageDigest {

public:

	md5MessageDigest();

	void update(const byte_t b);
	void update(const string& s);
	void update(const byte_t* buffer, const size_t len);
	void update(const byte_t* buffer, const size_t offset, const size_t len);

	void finalize();
	void finalize(const string& s);
	void finalize(const byte_t* buffer, const size_t len);
	void finalize(const byte_t* buffer, const size_t offset, const size_t len);

	size_t getDigestLength() const;
	const byte_t* getDigest() const;

	void reset();

protected:

	void init();
	void transformHelper();
	void transform();

	vmime_uint32 m_hash[4];

	union BlockType {
		vmime_uint32 b32[16];
		vmime_uint8 b8[64];
	};

	size_t m_byteCount;
	BlockType m_block;

	bool m_finalized;
};


} // md5
} // digest
} // security
} // vmime


#endif // VMIME_SECURITY_DIGEST_MD5_MD5MESSAGEDIGEST_HPP_INCLUDED

