/// The class IntVar is a subset of IntExpr. In addition to the
/// IntExpr protocol, it offers persistence, removing values from the domains,
/// and a finer model for events.
declare class IntVar
{
    //     public:
    //      explicit IntVar(Solver* const s);
    //      IntVar(Solver* const s, const std::string& name);
    //      ~IntVar() override {}

    //      bool IsVar() const override { return true; }
    //      IntVar* Var() override { return this; }

    //      /// This method returns the value of the variable. This method checks
    //      /// before that the variable is bound.
    //      virtual int64_t Value() const = 0;
    Value(): number;

    //      /// This method removes the value 'v' from the domain of the variable.
    //      virtual void RemoveValue(int64_t v) = 0;

    //      /// This method removes the interval 'l' .. 'u' from the domain of
    //      /// the variable. It assumes that 'l' <= 'u'.
    //      virtual void RemoveInterval(int64_t l, int64_t u) = 0;

    //      /// This method remove the values from the domain of the variable.
    //      virtual void RemoveValues(const std::vector<int64_t>& values);

    //      /// This method intersects the current domain with the values in the array.
    //      virtual void SetValues(const std::vector<int64_t>& values);

    //      /// This method attaches a demon that will be awakened when the
    //      /// variable is bound.
    //      virtual void WhenBound(Demon* d) = 0;
    //      /// This method attaches a closure that will be awakened when the
    //      /// variable is bound.
    //      void WhenBound(Solver::Closure closure) {
    //        WhenBound(solver()->MakeClosureDemon(std::move(closure)));
    //      }

    //    #if !defined(SWIG)
    //      /// This method attaches an action that will be awakened when the
    //      /// variable is bound.
    //      void WhenBound(Solver::Action action) {
    //        WhenBound(solver()->MakeActionDemon(std::move(action)));
    //      }
    //    #endif  // SWIG

    //      /// This method attaches a demon that will watch any domain
    //      /// modification of the domain of the variable.
    //      virtual void WhenDomain(Demon* d) = 0;
    //      /// This method attaches a closure that will watch any domain
    //      /// modification of the domain of the variable.
    //      void WhenDomain(Solver::Closure closure) {
    //        WhenDomain(solver()->MakeClosureDemon(std::move(closure)));
    //      }
    //    #if !defined(SWIG)
    //      /// This method attaches an action that will watch any domain
    //      /// modification of the domain of the variable.
    //      void WhenDomain(Solver::Action action) {
    //        WhenDomain(solver()->MakeActionDemon(std::move(action)));
    //      }
    //    #endif  // SWIG

    //      /// This method returns the number of values in the domain of the variable.
    //      virtual uint64_t Size() const = 0;

    //      /// This method returns whether the value 'v' is in the domain of the
    //      /// variable.
    //      virtual bool Contains(int64_t v) const = 0;

    //      /// Creates a hole iterator. When 'reversible' is false, the returned
    //      /// object is created on the normal C++ heap and the solver does NOT
    //      /// take ownership of the object.
    //      virtual IntVarIterator* MakeHoleIterator(bool reversible) const = 0;

    //      /// Creates a domain iterator. When 'reversible' is false, the
    //      /// returned object is created on the normal C++ heap and the solver
    //      /// does NOT take ownership of the object.
    //      virtual IntVarIterator* MakeDomainIterator(bool reversible) const = 0;

    //      /// Returns the previous min.
    //      virtual int64_t OldMin() const = 0;

    //      /// Returns the previous max.
    //      virtual int64_t OldMax() const = 0;

    //      virtual int VarType() const;

    //      /// Accepts the given visitor.
    //      void Accept(ModelVisitor* const visitor) const override;

    //      /// IsEqual
    //      virtual IntVar* IsEqual(int64_t constant) = 0;
    //      virtual IntVar* IsDifferent(int64_t constant) = 0;
    //      virtual IntVar* IsGreaterOrEqual(int64_t constant) = 0;
    //      virtual IntVar* IsLessOrEqual(int64_t constant) = 0;

    //      /// Returns the index of the variable.
    //      int index() const { return index_; }

};
