
// absl::Status
//
// The `absl::Status` class is generally used to gracefully handle errors
// across API boundaries (and in particular across RPC boundaries). Some of
// these errors may be recoverable, but others may not. Most
// functions which can produce a recoverable error should be designed to return
// either an `absl::Status` (or the similar `absl::StatusOr<T>`, which holds
// either an object of type `T` or an error).
//
// API developers should construct their functions to return `absl::OkStatus()`
// upon success, or an `absl::StatusCode` upon another type of error (e.g
// an `absl::StatusCode::kInvalidArgument` error). The API provides convenience
// functions to construct each status code.
//
// Example:
//
// absl::Status myFunction(absl::string_view fname, ...) {
//   ...
//   // encounter error
//   if (error condition) {
//     // Construct an absl::StatusCode::kInvalidArgument error
//     return absl::InvalidArgumentError("bad mode");
//   }
//   // else, return OK
//   return absl::OkStatus();
// }
//
// Users handling status error codes should prefer checking for an OK status
// using the `ok()` member function. Handling multiple error codes may justify
// use of switch statement, but only check for error codes you know how to
// handle; do not try to exhaustively match against all canonical error codes.
// Errors that cannot be handled should be logged and/or propagated for higher
// levels to deal with. If you do use a switch statement, make sure that you
// also provide a `default:` switch case, so that code does not break as other
// canonical codes are added to the API.
//
// Example:
//
//   absl::Status result = DoSomething();
//   if (!result.ok()) {
//     LOG(ERROR) << result;
//   }
//
//   // Provide a default if switching on multiple error codes
//   switch (result.code()) {
//     // The user hasn't authenticated. Ask them to reauth
//     case absl::StatusCode::kUnauthenticated:
//       DoReAuth();
//       break;
//     // The user does not have permission. Log an error.
//     case absl::StatusCode::kPermissionDenied:
//       LOG(ERROR) << result;
//       break;
//     // Propagate the error otherwise.
//     default:
//       return true;
//   }
//
// An `absl::Status` can optionally include a payload with more information
// about the error. Typically, this payload serves one of several purposes:
//
//   * It may provide more fine-grained semantic information about the error to
//     facilitate actionable remedies.
//   * It may provide human-readable contexual information that is more
//     appropriate to display to an end user.
//
// Example:
//
//   absl::Status result = DoSomething();
//   // Inform user to retry after 30 seconds
//   // See more error details in googleapis/google/rpc/error_details.proto
//   if (absl::IsResourceExhausted(result)) {
//     google::rpc::RetryInfo info;
//     info.retry_delay().seconds() = 30;
//     // Payloads require a unique key (a URL to ensure no collisions with
//     // other payloads), and an `absl::Cord` to hold the encoded data.
//     absl::string_view url = "type.googleapis.com/google.rpc.RetryInfo";
//     result.SetPayload(url, info.SerializeAsCord());
//     return result;
//   }
//
// For documentation see https://abseil.io/docs/cpp/guides/status.
//
// Returned Status objects may not be ignored. status_internal.h has a forward
// declaration of the form
// class ABSL_MUST_USE_RESULT Status;
export class Status
{
    // public:
    //  // Constructors

    //  // This default constructor creates an OK status with no message or payload.
    //  // Avoid this constructor and prefer explicit construction of an OK status
    //  // with `absl::OkStatus()`.
    //  Status();

    //  // Creates a status in the canonical error space with the specified
    //  // `absl::StatusCode` and error message.  If `code == absl::StatusCode::kOk`,  // NOLINT
    //  // `msg` is ignored and an object identical to an OK status is constructed.
    //  //
    //  // The `msg` string must be in UTF-8. The implementation may complain (e.g.,  // NOLINT
    //  // by printing a warning) if it is not.
    //  Status(absl::StatusCode code, absl::string_view msg);

    //  Status(const Status&);
    //  Status& operator=(const Status& x);

    //  // Move operators

    //  // The moved-from state is valid but unspecified.
    //  Status(Status&&) noexcept;
    //  Status& operator=(Status&&);

    //  ~Status();

    //  // Status::Update()
    //  //
    //  // Updates the existing status with `new_status` provided that `this->ok()`.
    //  // If the existing status already contains a non-OK error, this update has no
    //  // effect and preserves the current data. Note that this behavior may change
    //  // in the future to augment a current non-ok status with additional
    //  // information about `new_status`.
    //  //
    //  // `Update()` provides a convenient way of keeping track of the first error
    //  // encountered.
    //  //
    //  // Example:
    //  //   // Instead of "if (overall_status.ok()) overall_status = new_status"
    //  //   overall_status.Update(new_status);
    //  //
    //  void Update(const Status& new_status);
    //  void Update(Status&& new_status);

    //  // Status::ok()
    //  //
    //  // Returns `true` if `this->code()` == `absl::StatusCode::kOk`,
    //  // indicating the absence of an error.
    //  // Prefer checking for an OK status using this member function.
    //  ABSL_MUST_USE_RESULT bool ok() const;

    //  // Status::code()
    //  //
    //  // Returns the canonical error code of type `absl::StatusCode` of this status.
    //  absl::StatusCode code() const;

    //  // Status::raw_code()
    //  //
    //  // Returns a raw (canonical) error code corresponding to the enum value of
    //  // `google.rpc.Code` definitions within
    //  // https://github.com/googleapis/googleapis/blob/master/google/rpc/code.proto.
    //  // These values could be out of the range of canonical `absl::StatusCode`
    //  // enum values.
    //  //
    //  // NOTE: This function should only be called when converting to an associated
    //  // wire format. Use `Status::code()` for error handling.
    //  int raw_code() const;

    //  // Status::message()
    //  //
    //  // Returns the error message associated with this error code, if available.
    //  // Note that this message rarely describes the error code.  It is not unusual
    //  // for the error message to be the empty string. As a result, prefer
    //  // `operator<<` or `Status::ToString()` for debug logging.
    //  absl::string_view message() const;

    //  friend bool operator==(const Status&, const Status&);
    //  friend bool operator!=(const Status&, const Status&);

    //  // Status::ToString()
    //  //
    //  // Returns a string based on the `mode`. By default, it returns combination of
    //  // the error code name, the message and any associated payload messages. This
    //  // string is designed simply to be human readable and its exact format should
    //  // not be load bearing. Do not depend on the exact format of the result of
    //  // `ToString()` which is subject to change.
    //  //
    //  // The printed code name and the message are generally substrings of the
    //  // result, and the payloads to be printed use the status payload printer
    //  // mechanism (which is internal).
    //  std::string ToString(
    //      StatusToStringMode mode = StatusToStringMode::kDefault) const;

    //  // Status::IgnoreError()
    //  //
    //  // Ignores any errors. This method does nothing except potentially suppress
    //  // complaints from any tools that are checking that errors are not dropped on
    //  // the floor.
    //  void IgnoreError() const;

    //  // swap()
    //  //
    //  // Swap the contents of one status with another.
    //  friend void swap(Status& a, Status& b);

    //  //----------------------------------------------------------------------------
    //  // Payload Management APIs
    //  //----------------------------------------------------------------------------

    //  // A payload may be attached to a status to provide additional context to an
    //  // error that may not be satisfied by an existing `absl::StatusCode`.
    //  // Typically, this payload serves one of several purposes:
    //  //
    //  //   * It may provide more fine-grained semantic information about the error
    //  //     to facilitate actionable remedies.
    //  //   * It may provide human-readable contexual information that is more
    //  //     appropriate to display to an end user.
    //  //
    //  // A payload consists of a [key,value] pair, where the key is a string
    //  // referring to a unique "type URL" and the value is an object of type
    //  // `absl::Cord` to hold the contextual data.
    //  //
    //  // The "type URL" should be unique and follow the format of a URL
    //  // (https://en.wikipedia.org/wiki/URL) and, ideally, provide some
    //  // documentation or schema on how to interpret its associated data. For
    //  // example, the default type URL for a protobuf message type is
    //  // "type.googleapis.com/packagename.messagename". Other custom wire formats
    //  // should define the format of type URL in a similar practice so as to
    //  // minimize the chance of conflict between type URLs.
    //  // Users should ensure that the type URL can be mapped to a concrete
    //  // C++ type if they want to deserialize the payload and read it effectively.
    //  //
    //  // To attach a payload to a status object, call `Status::SetPayload()`,
    //  // passing it the type URL and an `absl::Cord` of associated data. Similarly,
    //  // to extract the payload from a status, call `Status::GetPayload()`. You
    //  // may attach multiple payloads (with differing type URLs) to any given
    //  // status object, provided that the status is currently exhibiting an error
    //  // code (i.e. is not OK).

    //  // Status::GetPayload()
    //  //
    //  // Gets the payload of a status given its unique `type_url` key, if present.
    //  absl::optional<absl::Cord> GetPayload(absl::string_view type_url) const;

    //  // Status::SetPayload()
    //  //
    //  // Sets the payload for a non-ok status using a `type_url` key, overwriting
    //  // any existing payload for that `type_url`.
    //  //
    //  // NOTE: This function does nothing if the Status is ok.
    //  void SetPayload(absl::string_view type_url, absl::Cord payload);

    //  // Status::ErasePayload()
    //  //
    //  // Erases the payload corresponding to the `type_url` key.  Returns `true` if
    //  // the payload was present.
    //  bool ErasePayload(absl::string_view type_url);

    //  // Status::ForEachPayload()
    //  //
    //  // Iterates over the stored payloads and calls the
    //  // `visitor(type_key, payload)` callable for each one.
    //  //
    //  // NOTE: The order of calls to `visitor()` is not specified and may change at
    //  // any time.
    //  //
    //  // NOTE: Any mutation on the same 'absl::Status' object during visitation is
    //  // forbidden and could result in undefined behavior.
    //  void ForEachPayload(
    //      absl::FunctionRef<void(absl::string_view, const absl::Cord&)> visitor)
    //      const;

    // private:
    //  friend Status CancelledError();

    //  // Creates a status in the canonical error space with the specified
    //  // code, and an empty error message.
    //  explicit Status(absl::StatusCode code);

    //  static void UnrefNonInlined(uintptr_t rep);
    //  static void Ref(uintptr_t rep);
    //  static void Unref(uintptr_t rep);

    //  // REQUIRES: !ok()
    //  // Ensures rep_ is not shared with any other Status.
    //  void PrepareToModify();

    //  const status_internal::Payloads* GetPayloads() const;
    //  status_internal::Payloads* GetPayloads();

    //  static bool EqualsSlow(const absl::Status& a, const absl::Status& b);

    //  // MSVC 14.0 limitation requires the const.
    //  static constexpr const char kMovedFromString[] =
    //      "Status accessed after move.";

    //  static const std::string* EmptyString();
    //  static const std::string* MovedFromString();

    //  // Returns whether rep contains an inlined representation.
    //  // See rep_ for details.
    //  static bool IsInlined(uintptr_t rep);

    //  // Indicates whether this Status was the rhs of a move operation. See rep_
    //  // for details.
    //  static bool IsMovedFrom(uintptr_t rep);
    //  static uintptr_t MovedFromRep();

    //  // Convert between error::Code and the inlined uintptr_t representation used
    //  // by rep_. See rep_ for details.
    //  static uintptr_t CodeToInlinedRep(absl::StatusCode code);
    //  static absl::StatusCode InlinedRepToCode(uintptr_t rep);

    //  // Converts between StatusRep* and the external uintptr_t representation used
    //  // by rep_. See rep_ for details.
    //  static uintptr_t PointerToRep(status_internal::StatusRep* r);
    //  static status_internal::StatusRep* RepToPointer(uintptr_t r);

    //  std::string ToStringSlow(StatusToStringMode mode) const;

    //  // Status supports two different representations.
    //  //  - When the low bit is off it is an inlined representation.
    //  //    It uses the canonical error space, no message or payload.
    //  //    The error code is (rep_ >> 2).
    //  //    The (rep_ & 2) bit is the "moved from" indicator, used in IsMovedFrom().
    //  //  - When the low bit is on it is an external representation.
    //  //    In this case all the data comes from a heap allocated Rep object.
    //  //    (rep_ - 1) is a status_internal::StatusRep* pointer to that structure.
    //  uintptr_t rep_;
}
