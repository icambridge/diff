<?hh //strict

namespace Diff;

class Differ<T>
{
    public function __construct(private string $header = "--- Original\n+++ New\n") {}

    public function diff(T $expected, T $actual): string
    {
        $generator = $this->generator($expected, $actual);
        $message = $generator->diff();


        return $this->header . "@@ @@\n" . $message;
    }

    private function generator(T $expected, T $actual): Generator\Generator
    {
        $expectedType = gettype($expected);
        if($expected instanceof Vector) {
            return new Generator\Vectors($expected, $actual);
        } else if ($expected instanceof Map) {
            return new Generator\Maps($expected, $actual);
        } else {
            return new Generator\Generic($expected, $actual);
        }
    }

}
