/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL v2
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   class definitions for the AVC/h.264 ES demultiplexer module

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef MTX_R_AVC_H
#define MTX_R_AVC_H

#include "common/common_pch.h"

#include "common/debugging.h"
#include "common/mpeg4_p10.h"
#include "merge/generic_reader.h"

class avc_es_reader_c: public generic_reader_c {
protected:
  static debugging_option_c ms_debug;

  int m_width, m_height;

  memory_cptr m_buffer;

public:
  avc_es_reader_c(const track_info_c &ti, const mm_io_cptr &in);

  virtual translatable_string_c get_format_name() const {
    return YT("AVC/h.264");
  }

  virtual void read_headers();
  virtual file_status_e read(generic_packetizer_c *ptzr, bool force = false);
  virtual void identify();
  virtual void create_packetizer(int64_t id);
  virtual bool is_providing_timecodes() const {
    return false;
  }

  static int probe_file(mm_io_c *in, uint64_t size);
};

#endif // MTX_R_AVC_H
