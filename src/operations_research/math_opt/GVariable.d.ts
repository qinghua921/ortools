// A value type that references a variable from ModelStorage. Usually this type
// is passed by copy.
export class Variable
{
    // public:
    //  // The typed integer used for ids.
    //  using IdType = VariableId;

    //  // Usually users will obtain variables using Model::AddVariable(). There
    //  // should be little for users to build this object from an ModelStorage.
    //  inline Variable(const ModelStorage* storage, VariableId id);

    //  // Each call to AddVariable will produce Variables id() increasing by one,
    //  // starting at zero. Deleted ids are NOT reused. Thus, if no variables are
    //  // deleted, the ids in the model will be consecutive.
    //  inline int64_t id() const;

    //  inline VariableId typed_id() const;
    //  inline const ModelStorage* storage() const;

    //  inline double lower_bound() const;
    //  inline double upper_bound() const;
    //  inline bool is_integer() const;
    //  inline absl::string_view name() const;

    //  template <typename H>
    //  friend H AbslHashValue(H h, const Variable& variable);
    //  friend std::ostream& operator<<(std::ostream& ostr, const Variable& variable);

    //  inline LinearExpression operator-() const;

    // private:
    //  const ModelStorage* storage_;
    //  VariableId id_;
};
