/// A constraint is the main modeling object. It provides two methods:
///   - Post() is responsible for creating the demons and attaching them to
///     immediate demons().
///   - InitialPropagate() is called once just after Post and performs
///     the initial propagation. The subsequent propagations will be performed
///     by the demons Posted during the post() method.
export class Constraint
{
    // public:
    //  explicit Constraint(Solver* const solver) : PropagationBaseObject(solver) {}
    //  ~Constraint() override {}

    //  /// This method is called when the constraint is processed by the
    //  /// solver. Its main usage is to attach demons to variables.
    //  virtual void Post() = 0;

    //  /// This method performs the initial propagation of the
    //  /// constraint. It is called just after the post.
    //  virtual void InitialPropagate() = 0;
    //  std::string DebugString() const override;

    //  /// Calls Post and then Propagate to initialize the constraints. This
    //  /// is usually done in the root node.
    //  void PostAndPropagate();

    //  /// Accepts the given visitor.
    //  virtual void Accept(ModelVisitor* const visitor) const;

    //  /// Is the constraint created by a cast from expression to integer variable?
    //  bool IsCastConstraint() const;

    //  /// Creates a Boolean variable representing the status of the constraint
    //  /// (false = constraint is violated, true = constraint is satisfied). It
    //  /// returns nullptr if the constraint does not support this API.
    //  virtual IntVar* Var();

};
