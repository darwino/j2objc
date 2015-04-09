// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Author: tball@google.com (Tom Ball)
//  Based on original Protocol Buffers design by
//  Sanjay Ghemawat, Jeff Dean, Kenton Varda, and others.

#ifndef GOOGLE_PROTOBUF_COMPILER_J2OBJC_MESSAGE_H__
#define GOOGLE_PROTOBUF_COMPILER_J2OBJC_MESSAGE_H__

#include <string>
#include <set>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/compiler/j2objc/j2objc_field.h>

namespace google {
namespace protobuf {
  namespace io {
    class Printer;             // printer.h
  }
}

namespace protobuf {
namespace compiler {
namespace j2objc {

class MessageGenerator {
 public:
  explicit MessageGenerator(const Descriptor* descriptor);
  ~MessageGenerator();

  void GenerateEnumHeader(io::Printer* printer);
  void GenerateMessageHeader(io::Printer* printer);
  void GenerateHeader(io::Printer* printer);
  void GenerateSource(io::Printer* printer);
  void GenerateMessageOrBuilder(io::Printer* printer);
  void GenerateExtensionRegistrationCode(io::Printer* printer);
  void CollectForwardDeclarations(set<string> &declarations) const;
  void CollectMessageOrBuilderForwardDeclarations(set<string> &declarations)
      const;
  void CollectMessageOrBuilderImports(set<string> &imports) const;
  void CollectSourceImports(set<string> &imports);

 private:
  void GenerateBuilderHeader(io::Printer* printer);
  void GenerateBuilderSource(io::Printer* printer);

  const Descriptor* descriptor_;
  FieldGeneratorMap field_generators_;

  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(MessageGenerator);
};

}  // namespace j2objc
}  // namespace compiler
}  // namespace protobuf
}  // namespace google

#endif  // GOOGLE_PROTOBUF_COMPILER_J2OBJC_MESSAGE_H__
