import { IntVar } from "./IntVar";

export class IntExpr
{
    //     public:
    //      explicit IntExpr(Solver* const s) : PropagationBaseObject(s) {}

    //    #ifndef SWIG
    //      // This type is neither copyable nor movable.
    //      IntExpr(const IntExpr&) = delete;
    //      IntExpr& operator=(const IntExpr&) = delete;
    //    #endif
    //      ~IntExpr() override {}

    //      virtual int64_t Min() const = 0;
    //      virtual void SetMin(int64_t m) = 0;
    //      virtual int64_t Max() const = 0;
    //      virtual void SetMax(int64_t m) = 0;

    //      /// By default calls Min() and Max(), but can be redefined when Min and Max
    //      /// code can be factorized.
    //      virtual void Range(int64_t* l, int64_t* u) {
    //        *l = Min();
    //        *u = Max();
    //      }
    //      /// This method sets both the min and the max of the expression.
    //      virtual void SetRange(int64_t l, int64_t u) {
    //        SetMin(l);
    //        SetMax(u);
    //      }

    //      /// This method sets the value of the expression.
    //      virtual void SetValue(int64_t v) { SetRange(v, v); }

    //      /// Returns true if the min and the max of the expression are equal.
    //      virtual bool Bound() const { return (Min() == Max()); }

    //      /// Returns true if the expression is indeed a variable.
    //      virtual bool IsVar() const { return false; }

    Var(): IntVar;

    //      /// Creates a variable from the expression and set the name of the
    //      /// resulting var. If the expression is already a variable, then it
    //      /// will set the name of the expression, possibly overwriting it.
    //      /// This is just a shortcut to Var() followed by set_name().
    //      IntVar* VarWithName(const std::string& name);

    //      /// Attach a demon that will watch the min or the max of the expression.
    //      virtual void WhenRange(Demon* d) = 0;
    //      /// Attach a demon that will watch the min or the max of the expression.
    //      void WhenRange(Solver::Closure closure) {
    //        WhenRange(solver()->MakeClosureDemon(std::move(closure)));
    //      }

    //    #if !defined(SWIG)
    //      /// Attach a demon that will watch the min or the max of the expression.
    //      void WhenRange(Solver::Action action) {
    //        WhenRange(solver()->MakeActionDemon(std::move(action)));
    //      }
    //    #endif  // SWIG

    //      /// Accepts the given visitor.
    //      virtual void Accept(ModelVisitor* visitor) const;
};
