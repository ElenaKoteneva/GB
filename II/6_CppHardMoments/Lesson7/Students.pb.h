// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Students.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Students_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Students_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Students_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Students_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Students_2eproto;
class FullName;
struct FullNameDefaultTypeInternal;
extern FullNameDefaultTypeInternal _FullName_default_instance_;
class Student;
struct StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
class StudentsGroup;
struct StudentsGroupDefaultTypeInternal;
extern StudentsGroupDefaultTypeInternal _StudentsGroup_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::FullName* Arena::CreateMaybeMessage<::FullName>(Arena*);
template<> ::Student* Arena::CreateMaybeMessage<::Student>(Arena*);
template<> ::StudentsGroup* Arena::CreateMaybeMessage<::StudentsGroup>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class FullName final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:FullName) */ {
 public:
  inline FullName() : FullName(nullptr) {}
  ~FullName() override;
  explicit constexpr FullName(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FullName(const FullName& from);
  FullName(FullName&& from) noexcept
    : FullName() {
    *this = ::std::move(from);
  }

  inline FullName& operator=(const FullName& from) {
    CopyFrom(from);
    return *this;
  }
  inline FullName& operator=(FullName&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const FullName& default_instance() {
    return *internal_default_instance();
  }
  static inline const FullName* internal_default_instance() {
    return reinterpret_cast<const FullName*>(
               &_FullName_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FullName& a, FullName& b) {
    a.Swap(&b);
  }
  inline void Swap(FullName* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FullName* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  FullName* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<FullName>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const FullName& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const FullName& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FullName* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "FullName";
  }
  protected:
  explicit FullName(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kSurnameFieldNumber = 2,
    kPatronymicFieldNumber = 3,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // string surname = 2;
  void clear_surname();
  const std::string& surname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_surname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_surname();
  PROTOBUF_NODISCARD std::string* release_surname();
  void set_allocated_surname(std::string* surname);
  private:
  const std::string& _internal_surname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_surname(const std::string& value);
  std::string* _internal_mutable_surname();
  public:

  // optional string patronymic = 3;
  bool has_patronymic() const;
  private:
  bool _internal_has_patronymic() const;
  public:
  void clear_patronymic();
  const std::string& patronymic() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_patronymic(ArgT0&& arg0, ArgT... args);
  std::string* mutable_patronymic();
  PROTOBUF_NODISCARD std::string* release_patronymic();
  void set_allocated_patronymic(std::string* patronymic);
  private:
  const std::string& _internal_patronymic() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_patronymic(const std::string& value);
  std::string* _internal_mutable_patronymic();
  public:

  // @@protoc_insertion_point(class_scope:FullName)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr surname_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr patronymic_;
  friend struct ::TableStruct_Students_2eproto;
};
// -------------------------------------------------------------------

class Student final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Student) */ {
 public:
  inline Student() : Student(nullptr) {}
  ~Student() override;
  explicit constexpr Student(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Student(const Student& from);
  Student(Student&& from) noexcept
    : Student() {
    *this = ::std::move(from);
  }

  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student& operator=(Student&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Student& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
               &_Student_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Student& a, Student& b) {
    a.Swap(&b);
  }
  inline void Swap(Student* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Student* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Student>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Student& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Student& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Student";
  }
  protected:
  explicit Student(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMarksFieldNumber = 2,
    kFullnameFieldNumber = 1,
    kAverageScoreFieldNumber = 3,
  };
  // repeated uint32 marks = 2;
  int marks_size() const;
  private:
  int _internal_marks_size() const;
  public:
  void clear_marks();
  private:
  uint32_t _internal_marks(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      _internal_marks() const;
  void _internal_add_marks(uint32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      _internal_mutable_marks();
  public:
  uint32_t marks(int index) const;
  void set_marks(int index, uint32_t value);
  void add_marks(uint32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
      marks() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
      mutable_marks();

  // .FullName fullname = 1;
  bool has_fullname() const;
  private:
  bool _internal_has_fullname() const;
  public:
  void clear_fullname();
  const ::FullName& fullname() const;
  PROTOBUF_NODISCARD ::FullName* release_fullname();
  ::FullName* mutable_fullname();
  void set_allocated_fullname(::FullName* fullname);
  private:
  const ::FullName& _internal_fullname() const;
  ::FullName* _internal_mutable_fullname();
  public:
  void unsafe_arena_set_allocated_fullname(
      ::FullName* fullname);
  ::FullName* unsafe_arena_release_fullname();

  // uint32 average_score = 3;
  void clear_average_score();
  uint32_t average_score() const;
  void set_average_score(uint32_t value);
  private:
  uint32_t _internal_average_score() const;
  void _internal_set_average_score(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:Student)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t > marks_;
  mutable std::atomic<int> _marks_cached_byte_size_;
  ::FullName* fullname_;
  uint32_t average_score_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Students_2eproto;
};
// -------------------------------------------------------------------

class StudentsGroup  :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:StudentsGroup) */ {
 public:
  inline StudentsGroup() : StudentsGroup(nullptr) {}
  ~StudentsGroup() override;
  explicit constexpr StudentsGroup(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StudentsGroup(const StudentsGroup& from);
  StudentsGroup(StudentsGroup&& from) noexcept
    : StudentsGroup() {
    *this = ::std::move(from);
  }


  inline StudentsGroup& operator=(const StudentsGroup& from) {
    CopyFrom(from);
    return *this;
  }
  inline StudentsGroup& operator=(StudentsGroup&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const StudentsGroup& default_instance() {
    return *internal_default_instance();
  }
  static inline const StudentsGroup* internal_default_instance() {
    return reinterpret_cast<const StudentsGroup*>(
               &_StudentsGroup_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(StudentsGroup& a, StudentsGroup& b) {
    a.Swap(&b);
  }
  inline void Swap(StudentsGroup* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StudentsGroup* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  StudentsGroup* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<StudentsGroup>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const StudentsGroup& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const StudentsGroup& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StudentsGroup* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "StudentsGroup";
  }
  protected:
  explicit StudentsGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStudentFieldNumber = 1,
  };
  // repeated .Student student = 1;
  int student_size() const;
  private:
  int _internal_student_size() const;
  public:
  void clear_student();
  ::Student* mutable_student(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Student >*
      mutable_student();
  private:
  const ::Student& _internal_student(int index) const;
  ::Student* _internal_add_student();
  public:
  const ::Student& student(int index) const;
  ::Student* add_student();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Student >&
      student() const;

  // @@protoc_insertion_point(class_scope:StudentsGroup)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Student > student_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Students_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FullName

// string name = 1;
inline void FullName::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& FullName::name() const {
  // @@protoc_insertion_point(field_get:FullName.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:FullName.name)
}
inline std::string* FullName::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:FullName.name)
  return _s;
}
inline const std::string& FullName::_internal_name() const {
  return name_.Get();
}
inline void FullName::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_name() {
  // @@protoc_insertion_point(field_release:FullName.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FullName::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:FullName.name)
}

// string surname = 2;
inline void FullName::clear_surname() {
  surname_.ClearToEmpty();
}
inline const std::string& FullName::surname() const {
  // @@protoc_insertion_point(field_get:FullName.surname)
  return _internal_surname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_surname(ArgT0&& arg0, ArgT... args) {
 
 surname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:FullName.surname)
}
inline std::string* FullName::mutable_surname() {
  std::string* _s = _internal_mutable_surname();
  // @@protoc_insertion_point(field_mutable:FullName.surname)
  return _s;
}
inline const std::string& FullName::_internal_surname() const {
  return surname_.Get();
}
inline void FullName::_internal_set_surname(const std::string& value) {
  
  surname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_surname() {
  
  return surname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_surname() {
  // @@protoc_insertion_point(field_release:FullName.surname)
  return surname_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FullName::set_allocated_surname(std::string* surname) {
  if (surname != nullptr) {
    
  } else {
    
  }
  surname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), surname,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (surname_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    surname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:FullName.surname)
}

// optional string patronymic = 3;
inline bool FullName::_internal_has_patronymic() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool FullName::has_patronymic() const {
  return _internal_has_patronymic();
}
inline void FullName::clear_patronymic() {
  patronymic_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& FullName::patronymic() const {
  // @@protoc_insertion_point(field_get:FullName.patronymic)
  return _internal_patronymic();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_patronymic(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 patronymic_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:FullName.patronymic)
}
inline std::string* FullName::mutable_patronymic() {
  std::string* _s = _internal_mutable_patronymic();
  // @@protoc_insertion_point(field_mutable:FullName.patronymic)
  return _s;
}
inline const std::string& FullName::_internal_patronymic() const {
  return patronymic_.Get();
}
inline void FullName::_internal_set_patronymic(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  patronymic_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_patronymic() {
  _has_bits_[0] |= 0x00000001u;
  return patronymic_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_patronymic() {
  // @@protoc_insertion_point(field_release:FullName.patronymic)
  if (!_internal_has_patronymic()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = patronymic_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (patronymic_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    patronymic_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void FullName::set_allocated_patronymic(std::string* patronymic) {
  if (patronymic != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  patronymic_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), patronymic,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (patronymic_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    patronymic_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:FullName.patronymic)
}

// -------------------------------------------------------------------

// Student

// .FullName fullname = 1;
inline bool Student::_internal_has_fullname() const {
  return this != internal_default_instance() && fullname_ != nullptr;
}
inline bool Student::has_fullname() const {
  return _internal_has_fullname();
}
inline void Student::clear_fullname() {
  if (GetArenaForAllocation() == nullptr && fullname_ != nullptr) {
    delete fullname_;
  }
  fullname_ = nullptr;
}
inline const ::FullName& Student::_internal_fullname() const {
  const ::FullName* p = fullname_;
  return p != nullptr ? *p : reinterpret_cast<const ::FullName&>(
      ::_FullName_default_instance_);
}
inline const ::FullName& Student::fullname() const {
  // @@protoc_insertion_point(field_get:Student.fullname)
  return _internal_fullname();
}
inline void Student::unsafe_arena_set_allocated_fullname(
    ::FullName* fullname) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(fullname_);
  }
  fullname_ = fullname;
  if (fullname) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Student.fullname)
}
inline ::FullName* Student::release_fullname() {
  
  ::FullName* temp = fullname_;
  fullname_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::FullName* Student::unsafe_arena_release_fullname() {
  // @@protoc_insertion_point(field_release:Student.fullname)
  
  ::FullName* temp = fullname_;
  fullname_ = nullptr;
  return temp;
}
inline ::FullName* Student::_internal_mutable_fullname() {
  
  if (fullname_ == nullptr) {
    auto* p = CreateMaybeMessage<::FullName>(GetArenaForAllocation());
    fullname_ = p;
  }
  return fullname_;
}
inline ::FullName* Student::mutable_fullname() {
  ::FullName* _msg = _internal_mutable_fullname();
  // @@protoc_insertion_point(field_mutable:Student.fullname)
  return _msg;
}
inline void Student::set_allocated_fullname(::FullName* fullname) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete fullname_;
  }
  if (fullname) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::FullName>::GetOwningArena(fullname);
    if (message_arena != submessage_arena) {
      fullname = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, fullname, submessage_arena);
    }
    
  } else {
    
  }
  fullname_ = fullname;
  // @@protoc_insertion_point(field_set_allocated:Student.fullname)
}

// repeated uint32 marks = 2;
inline int Student::_internal_marks_size() const {
  return marks_.size();
}
inline int Student::marks_size() const {
  return _internal_marks_size();
}
inline void Student::clear_marks() {
  marks_.Clear();
}
inline uint32_t Student::_internal_marks(int index) const {
  return marks_.Get(index);
}
inline uint32_t Student::marks(int index) const {
  // @@protoc_insertion_point(field_get:Student.marks)
  return _internal_marks(index);
}
inline void Student::set_marks(int index, uint32_t value) {
  marks_.Set(index, value);
  // @@protoc_insertion_point(field_set:Student.marks)
}
inline void Student::_internal_add_marks(uint32_t value) {
  marks_.Add(value);
}
inline void Student::add_marks(uint32_t value) {
  _internal_add_marks(value);
  // @@protoc_insertion_point(field_add:Student.marks)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
Student::_internal_marks() const {
  return marks_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >&
Student::marks() const {
  // @@protoc_insertion_point(field_list:Student.marks)
  return _internal_marks();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
Student::_internal_mutable_marks() {
  return &marks_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< uint32_t >*
Student::mutable_marks() {
  // @@protoc_insertion_point(field_mutable_list:Student.marks)
  return _internal_mutable_marks();
}

// uint32 average_score = 3;
inline void Student::clear_average_score() {
  average_score_ = 0u;
}
inline uint32_t Student::_internal_average_score() const {
  return average_score_;
}
inline uint32_t Student::average_score() const {
  // @@protoc_insertion_point(field_get:Student.average_score)
  return _internal_average_score();
}
inline void Student::_internal_set_average_score(uint32_t value) {
  
  average_score_ = value;
}
inline void Student::set_average_score(uint32_t value) {
  _internal_set_average_score(value);
  // @@protoc_insertion_point(field_set:Student.average_score)
}

// -------------------------------------------------------------------

// StudentsGroup

// repeated .Student student = 1;
inline int StudentsGroup::_internal_student_size() const {
  return student_.size();
}
inline int StudentsGroup::student_size() const {
  return _internal_student_size();
}
inline void StudentsGroup::clear_student() {
  student_.Clear();
}
inline ::Student* StudentsGroup::mutable_student(int index) {
  // @@protoc_insertion_point(field_mutable:StudentsGroup.student)
  return student_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Student >*
StudentsGroup::mutable_student() {
  // @@protoc_insertion_point(field_mutable_list:StudentsGroup.student)
  return &student_;
}
inline const ::Student& StudentsGroup::_internal_student(int index) const {
  return student_.Get(index);
}
inline const ::Student& StudentsGroup::student(int index) const {
  // @@protoc_insertion_point(field_get:StudentsGroup.student)
  return _internal_student(index);
}
inline ::Student* StudentsGroup::_internal_add_student() {
  return student_.Add();
}
inline ::Student* StudentsGroup::add_student() {
  ::Student* _add = _internal_add_student();
  // @@protoc_insertion_point(field_add:StudentsGroup.student)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Student >&
StudentsGroup::student() const {
  // @@protoc_insertion_point(field_list:StudentsGroup.student)
  return student_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Students_2eproto
